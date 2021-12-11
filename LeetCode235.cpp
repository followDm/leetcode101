#include<array>
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;

struct TreeNode{
	int val;
	struct TreeNode *left,*right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
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
            } else {
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        while (true) {
            if (p->val < ancestor->val && q->val < ancestor->val) {
                ancestor = ancestor->left;
            }
            else if (p->val > ancestor->val && q->val > ancestor->val) {
                ancestor = ancestor->right;
            }
            else {
                break;
            }
        }
        return ancestor;
    }
    // 自己改成这个方法了
    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
        TreeNode* ancestor = root;
        while (true) {
            if (p < ancestor->val && q < ancestor->val) {
                ancestor = ancestor->left;
            } else if (p > ancestor->val && q > ancestor->val) {
                ancestor = ancestor->right;
            } else {
                break;
            }
        }
        return ancestor;
    }
};
int main(){
    int n1 = 0, n2 = 0, t = 0, target = 0, p = 0, q = 0;
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
    cout << "num of p: ";
    cin >> p;
    cout << "num of q: ";
    cin >> q;
    Solution sol;
    TreeNode* bt = sol.buildTree(nums1, nums2);
    cout << sol.lowestCommonAncestor(bt, p, q);
    return 0;
}
/*给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// number of num1: 9
// 6 2 0 4 3 5 8 7 9
// number of num2: 9
// 0 2 3 4 5 6 7 8 9
// num of p: 3
// num of q: 5