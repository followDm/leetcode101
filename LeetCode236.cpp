#include<array>
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;

typedef struct TreeNode{
	int val;
	struct TreeNode *left,*right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
}TreeNode, *NodeTree;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) {
            return nullptr;
        }
        auto root = new TreeNode(postorder[postorder.size() - 1]);
        auto s = stack<TreeNode*>();
        s.push(root);
        int inorderIndex = inorder.size() - 1;
        for (int i = int(postorder.size()) - 2; i >= 0; i--) {
            int postorderVal = postorder[i];
            auto node = s.top();
            if (node->val != inorder[inorderIndex]) {
                node->right = new TreeNode(postorderVal);
                s.push(node->right);
            } else {
                while (!s.empty() && s.top()->val == inorder[inorderIndex]) {
                    node = s.top();
                    s.pop();
                    inorderIndex--;
                }
                node->left = new TreeNode(postorderVal);
                s.push(node->left);
            }
        }
        return root;
    }
    TreeNode* ans;
    bool dfs(TreeNode* root, int p, int q) {
        if (root == nullptr) 
            return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root->val == p || root->val == q) && (lson || rson))) {
            ans = root;
        } 
        return lson || rson || (root->val == p || root->val == q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
        dfs(root, p, q);
        return ans;
    }
};
int main(){
    int n1 = 0, n2 = 0, t = 0, target = 0, p = 0, q = 0;
    cout << "number of num1: ";
    cin >> n1;
    vector<int> nums1;
    for (int i = 1; i <= n1; i++){
        cin >> t;
        nums1.push_back(t);
    }
    cout << "number of num2: ";
    cin >> n2;
    vector<int> nums2;
    for (int i = 1; i <= n2; i++){
        cin >> t;
        nums2.push_back(t);
    }
    cout << "num of p: ";
    cin >> p;
    cout << "num of q: ";
    cin >> q;
    Solution sol;
    NodeTree bt = sol.buildTree(nums1, nums2);
    sol.lowestCommonAncestor(bt, p, q);
    return 0;
}
//中序和后序
// number of num1: 9
// 6 5 7 2 4 3 0 1 8
// number of num2: 9
// 6 7 4 2 5 0 8 1 3
// num of p: 6
// num of q: 5