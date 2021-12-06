#include<array>
#include<vector>
#include<stack>
#include<unordered_map>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // TreeNode* PreInCreat(vector<int> &A, vector<int> &B, int l1, int h1, int l2, int h2) {
    //     TreeNode* root= (TreeNode*) malloc (sizeof (TreeNode) ) ;
    //     root->val=A[l1];
    //     int i = 0;
    //     for (i = l2; B[i] != root->val; i++);
    //     //子树长度
    //     int llen = i - l2;
    //     int rlen = h2 - i;
    //     if (llen)
    //         root->left = PreInCreat(A, B, l1+1, l1+llen, l2, l2+llen-1);
    //     else
    //         root->left = nullptr;

    //     if (rlen)
    //         root->right = PreInCreat(A, B, h1-rlen+1, h1, h2-rlen+1, h2);
    //     else
    //         root->right = nullptr;
    //     return root;
    // }
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
    bool check(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

int main(){
    int n1 = 0, n2 = 0, t = 0;
    cout << "number of nodes: ";
    cin >> n1;
    cout << "preorder: ";
    vector<int> nums1;
    for (int i = 1; i <= n1; i++){
        cin >> t;
        // 如果定义了(n)等，不能这么push
        nums1.push_back(t);
    }
    cout << "inorder: ";
    vector<int> nums2;
    for (int i = 1; i <= n1; i++){
        cin >> t;
        nums2.push_back(t);
    }
    Solution sol;
    TreeNode* bt = sol.buildTree(nums1, nums2);
    cout << boolalpha << sol.isSymmetric(bt);
    return 0;
}
/*给定一个二叉树，检查它是否是镜像对称的。*/
// number of nums1: 7
// 1 2 3 4 2 4 3
// number of nums1: 7
// 3 2 4 1 4 2 3
// true