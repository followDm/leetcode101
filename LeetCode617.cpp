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
    BiTNode* mergeTrees(BiTNode* t1, BiTNode* t2) {
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        auto merged = new BiTNode(t1->data + t2->data);
        merged->lchild = mergeTrees(t1->lchild, t2->lchild);
        merged->rchild = mergeTrees(t1->rchild, t2->rchild);
        return merged;
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
    cout << "number of num1: ";
    cin >> n1;
    vector<int> nums3;
    for (int i = 1; i <= n1; i++){
        cin >> t;
        nums3.push_back(t);
    }
    cout << "number of num2: ";
    cin >> n2;
    vector<int> nums4;
    for (int i = 1; i <= n2; i++){
        cin >> t;
        nums4.push_back(t);
    }
    Solution sol;
    BiTree bt1 = sol.buildTree(nums1, nums2);
    BiTree bt2 = sol.buildTree(nums3, nums4);
    sol.mergeTrees(bt1, bt2);
    return 0;
}
// number of num1: 4
// 1 3 5 2
// number of num2: 4
// 5 3 1 2
// number of num3: 5
// 2 1 4 3 7
// number of num4: 5
// 1 4 2 3 7