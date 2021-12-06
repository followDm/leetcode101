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
private:
    unordered_map<int, int> index;
public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        int preorder_root = preorder_left;
        int inorder_root = index[preorder[preorder_root]];
        
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        int size_left_subtree = inorder_root - inorder_left;
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    int maxDepth(TreeNode* root){
        return root ? 1 + max(maxDepth(root->left),maxDepth(root->right)) : 0;
    }
};
int main(){
    int n1 = 0, n2 = 0, t = 0;
    cout << "number of nodes: ";
    cin >> n1;
    cout << "preorder: ";
    vector<int> nums1(n1);
    for (int i = 0; i < n1; i++){
        cin >> t;
        nums1[i] = t;
    }
    cout << "inorder: ";
    vector<int> nums2(n1);
    for (int i = 0; i < n1; i++){
        cin >> t;
        nums2[i] = t;
    }
    Solution sol;
    TreeNode* bt = sol.buildTree(nums1, nums2);
    cout << sol.maxDepth(bt);
    return 0;
}
/*给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。*/
// number of nums1: 5
// 3 9 20 15 7
// number of nums1: 5
// 9 3 15 20 7
// 3