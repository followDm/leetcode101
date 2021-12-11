#include<array>
#include<vector>
#include<stack>
#include<iostream>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); ++i) {
            int preorderVal = preorder[i];
            TreeNode* node = stk.top();
            if (node->val != inorder[inorderIndex]) {
                node->left = new TreeNode(preorderVal);
                stk.push(node->left);
            }
            else {
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
                    node = stk.top();
                    stk.pop();
                    ++inorderIndex;
                }
                node->right = new TreeNode(preorderVal);
                stk.push(node->right);
            }
        }
        return root;
    }
    static constexpr int MAX_N = 1000 + 5;
    static constexpr int MOD = int(1E9) + 7;

    bool vis[MAX_N];
    int p[MAX_N], tot;
    void getPrime() {
        vis[0] = vis[1] = 1; tot = 0;
        for (int i = 2; i < MAX_N; ++i) {
            if (!vis[i]) p[++tot] = i;
            for (int j = 1; j <= tot && i * p[j] < MAX_N; ++j) {
                vis[i * p[j]] = 1;
                if (i % p[j] == 0) break;
            }
        }
    }

    struct Status {
        int f, s; // f 为哈希值 | s 为子树大小
        Status(int f_ = 0, int s_ = 0) 
            : f(f_), s(s_) {}
    };

    unordered_map <TreeNode *, Status> hS, hT;

    void dfs(TreeNode *o, unordered_map <TreeNode *, Status> &h) {
        h[o] = Status(o->val, 1);
        if (!o->left && !o->right) return;
        if (o->left) {
            dfs(o->left, h);
            h[o].s += h[o->left].s;
            h[o].f = (h[o].f + (31LL * h[o->left].f * p[h[o->left].s]) % MOD) % MOD;
        }
        if (o->right) {
            dfs(o->right, h);
            h[o].s += h[o->right].s;
            h[o].f = (h[o].f + (179LL * h[o->right].f * p[h[o->right].s]) % MOD) % MOD;
        }
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        getPrime();
        dfs(s, hS);
        dfs(t, hT);

        int tHash = hT[t].f;
        for (const auto &[k, v]: hS) {
            if (v.f == tHash) {
                return true;
            }
        } 

        return false;
    }
};

int main(){
    int n1 = 0, n2 = 0, t = 0, target = 0;
    cout << "number of nodes: ";
    cin >> n1;
    cout << "preorder: ";
    vector<int> nums1;
    for (int i = 1; i <= n1; i++){
        cin >> t;
        nums1.push_back(t);
    }
    cout << "inorder: ";
    vector<int> nums2;
    for (int i = 1; i <= n1; i++){
        cin >> t;
        nums2.push_back(t);
    }
    cout << "number of nodes: ";
    cin >> n1;
    cout << "preorder: ";
    vector<int> nums3;
    for (int i = 1; i <= n1; i++){
        cin >> t;
        nums3.push_back(t);
    }
    cout << "inorder: ";
    vector<int> nums4;
    for (int i = 1; i <= n1; i++){
        cin >> t;
        nums4.push_back(t);
    }
    Solution sol;
    TreeNode* bt1 = sol.buildTree(nums1, nums2);
    TreeNode* bt2 = sol.buildTree(nums3, nums4);
    cout << boolalpha << sol.isSubtree(bt1, bt2);
    return 0;
}
/*给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。

二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subtree-of-another-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// 可以使用很奇妙的先序遍历，然后匹配字符串
// number of num1: 5
// 3 4 1 2 5
// number of num2: 5
// 1 4 2 3 5
// number of num3: 3
// 4 1 2
// number of num4: 3
// 1 4 2