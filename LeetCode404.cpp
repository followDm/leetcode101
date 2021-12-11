#include<array>
#include<vector>
#include<stack>
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
    bool isLeafNode(TreeNode* node) {
        return !node->left && !node->right;
    }
    int dfs(TreeNode* node) {
        int ans = 0;
        if (node->left) {
            ans += isLeafNode(node->left) ? node->left->val : dfs(node->left);
        }
        if (node->right && !isLeafNode(node->right)) {
            ans += dfs(node->right);
        }
        return ans;
    }
    int sumOfleftLeaves(TreeNode* root) {
        return root ? dfs(root) : 0;
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
    Solution sol;
    TreeNode* bt1 = sol.buildTree(nums1, nums2);
    cout << sol.sumOfleftLeaves(bt1);
    return 0;
}
/*计算给定二叉树的所有左叶子之和。*/
// number of num1: 5
// 3 9 20 15 7
// number of num2: 5
// 9 3 15 20 7
// 24