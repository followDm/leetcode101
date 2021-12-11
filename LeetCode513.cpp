#include<array>
#include<vector>
#include<queue>
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
    auto findBottomlchildValue(TreeNode* root) {
        auto q = queue<TreeNode*>();
        auto s = stack<TreeNode*>();
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                auto left = node->left, right = node->right;
                if (left != nullptr) {
                    q.push(left);
                    if (left->left == nullptr && left->right == nullptr) {
                        // 将符合左的叶子结点放入栈
                        s.push(left);
                    }
                } else if (right != nullptr) {
                    q.push(right);
                }
            }
        }
        // 如果栈非空，则返回栈顶的值
        return s.empty() ? -1 : s.top()->val;
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
    TreeNode* bt = sol.buildTree(nums1, nums2);
    cout << sol.findBottomlchildValue(bt);
    return 0;
}
/*给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

假设二叉树中至少有一个节点。*/
// number of num1: 7
// 1 2 4 3 5 7 6
// number of num2: 7
// 4 2 1 7 5 3 6
// 7