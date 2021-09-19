#include<array>
#include<vector>
#include<queue>
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
    BiTNode* getSuccessor(BiTNode* node) {
        BiTNode* succ = node->rchild;
        while (succ->lchild != nullptr && succ->lchild != node) {
            succ = succ->lchild;
        }
        return succ;
    }

    BiTNode* convertBST(BiTNode* root) {
        int sum = 0;
        BiTNode* node = root;

        while (node != nullptr) {
            if (node->rchild == nullptr) {
                sum += node->data;
                node->data = sum;
                node = node->lchild;
            } else {
                BiTNode* succ = getSuccessor(node);
                if (succ->lchild == nullptr) {
                    succ->lchild = node;
                    node = node->rchild;
                } else {
                    succ->lchild = nullptr;
                    sum += node->data;
                    node->data = sum;
                    node = node->lchild;
                }
            }
        }

        return root;
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
    BiTree bt1 = sol.buildTree(nums1, nums2);
    sol.convertBST(bt1);
    return 0;
}
// number of num1: 9
// 4 1 0 2 3 6 5 7 8
// number of num2: 9
// 0 1 2 3 4 5 6 7 8