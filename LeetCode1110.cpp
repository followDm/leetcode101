#include<array>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
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
    vector<TreeNode*> deiNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        unordered_set<int> diet(to_delete.begin(), to_delete.end());
        root = helper(root, diet, forest);
        if (root) {
            forest.push_back(root);
        }
        return forest;
    }

    TreeNode* helper(TreeNode* root, unordered_set<int> & diet, vector<TreeNode*> &forest) {
        if (!root) {
            return root;
        }
        root->left = helper(root->left, diet, forest);
        root->right = helper(root->right, diet, forest);
        if(diet.count(root->val)) {
            if (root->left) {
                forest.push_back(root->left);
            }
            if (root->right) {
                forest.push_back(root->right);
            }
            root = nullptr;
        }
        return root;
    }
};
int main(){
    int n1 = 0, n2 = 0, t = 0, target;
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
    cout << "number of dels: ";
    cin >> target;
    vector<int> del;
    for (int i = 1; i <= target; i++){
        cin >> t;
        del.push_back(t);
    }
    Solution sol;
    TreeNode* bt = sol.buildTree(nums1, nums2);
    sol.deiNodes(bt, del);
    return 0;
}
/*?????????????????????????????root????????????????????????????????????????????????

????????????????????to_delete??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????

?????????????????????????????????????????????????????????????????????

??????????????????LeetCode???
?????????https://leetcode-cn.com/problems/delete-nodes-and-return-forest
??????????????????????????????????????????????????????????????????????????????????????????????????????*/
// number of num1: 7
// 1 2 4 5 3 6 7
// number of num2: 7
// 4 2 5 1 6 3 7
// number of dels: 2
// 3 5