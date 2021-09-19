#include<array>
#include<vector>
#include<stack>
#include<iostream>
using namespace std;

typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
    BiTNode(int x) : data(x), lchild(nullptr), rchild(nullptr){};
}BiTNode, *BiTree;

class Solution {
public:
    BiTNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size()) {
            return nullptr;
        }
        BiTNode* root = new BiTNode(preorder[0]);
        stack<BiTNode*> stk;
        stk.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); ++i) {
            int preorderVal = preorder[i];
            BiTNode* node = stk.top();
            if (node->data != inorder[inorderIndex]) {
                node->lchild = new BiTNode(preorderVal);
                stk.push(node->lchild);
            } else {
                while (!stk.empty() && stk.top()->data == inorder[inorderIndex]) {
                    node = stk.top();
                    stk.pop();
                    ++inorderIndex;
                }
                node->rchild = new BiTNode(preorderVal);
                stk.push(node->rchild);
            }
        }
        return root;
    }

    vector<int> preorderTraversal(BiTNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        stack<BiTNode*> stk;
        BiTNode* node = root;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                res.emplace_back(node->data);
                stk.emplace(node);
                node = node->lchild;
            }
            node = stk.top();
            stk.pop();
            node = node->rchild;
        }
        return res;
    }
};
int main(){
    int n1 = 0, n2 = 0, t = 0, target = 0;
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
    Solution sol;
    BiTree bt = sol.buildTree(nums1, nums2);
    sol.preorderTraversal(bt);
    return 0;
}
// 非递归
// number of num1: 5
// 3 9 20 15 7
// number of num2: 5
// 9 3 15 20 7