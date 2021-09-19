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
    bool isLeafNode(BiTNode* node) {
        return !node->lchild && !node->rchild;
    }
    int dfs(BiTNode* node) {
        int ans = 0;
        if (node->lchild) {
            ans += isLeafNode(node->lchild) ? node->lchild->data : dfs(node->lchild);
        }
        if (node->rchild && !isLeafNode(node->rchild)) {
            ans += dfs(node->rchild);
        }
        return ans;
    }
    int sumOflchildLeaves(BiTNode* root) {
        return root ? dfs(root) : 0;
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
    cout << sol.sumOflchildLeaves(bt1);
    return 0;
}
// number of num1: 5
// 3 9 20 15 7
// number of num2: 5
// 9 3 15 20 7
// 24