#include<list>
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) 
            return nullptr;   // key not found in bst

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // case 1:  if the root itself is a leaf node
            if (!root->left && !root->right) {
                return nullptr;
            }

            // case 2:  if the root only has right child
            if (!root->left && root->right) {
                return root->right;
            }

            // case 3:  if the root only has left child
            if (root->left && !root->right) {
                return root->left;
            }

            // case 4:  if the root has both left and right child
            if (root->left && root->right) {
                //  find the successor from right subtree:
                //  1. the successor must be the samllest element in subtree
                //  2. the successor could be either the right or left child of its ancestor
                auto ancestor = root;
                auto successor = root->right;
                while (successor->left) {
                    ancestor = successor;
                    successor = successor->left;
                }
                root->val = successor->val;
                if (successor == ancestor->right) {
                    ancestor->right = deleteNode(successor, successor->val);
                } else {
                    ancestor->left = deleteNode(successor, successor->val);
                }
            }
        }
        return root;
    }
};
int main(){
    int n1 = 0, n2 = 0, t = 0, target = 0;
    cout << "number of nodes: ";
    cin >> n1;
    cout << "inorder: ";
    vector<int> nums1;
    for (int i = 1; i <= n1; i++){
        cin >> t;
        nums1.push_back(t);
    }
    cout << "postorder: ";
    vector<int> nums2;
    for (int i = 1; i <= n1; i++){
        cin >> t;
        nums2.push_back(t);
    }
    int k = 0;
    cout << "target: ";
    cin >> k;
    Solution sol;
    NodeTree bt = sol.buildTree(nums1, nums2);
    auto res = sol.deleteNode(bt, k);
    return 0;
}
/*给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-node-in-a-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
//中序和后序
// number of num1: 9
// 1 2 3 4 5 6 7 8 9
// number of num2: 9
// 1 2 4 3 7 9 8 6 5
// target: 2