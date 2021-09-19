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
    void recoverTree(BiTNode* root) {
        stack<BiTNode*> stk;
        BiTNode* x = nullptr;
        BiTNode* y = nullptr;
        BiTNode* pred = nullptr;

        while (!stk.empty() || root != nullptr) {
            while (root != nullptr) {
                stk.push(root);
                root = root->lchild;
            }
            root = stk.top();
            stk.pop();
            if (pred != nullptr && root->data < pred->data) {
                y = root;
                if (x == nullptr) {
                    x = pred;
                }
                else break;
            }
            pred = root;
            root = root->rchild;
        }
        swap(x->data, y->data);
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
    sol.recoverTree(bt);
    return 0;
}
// 非递归
// number of num1: 4
// 3 1 4 2
// number of num2: 4
// 1 3 2 4