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
    bool check(BiTNode *o, BiTNode *t) {
        if (!o && !t) {
            return true;
        }
        if ((o && !t) || (!o && t) || (o->data != t->data)) {
            return false;
        }
        return check(o->lchild, t->lchild) && check(o->rchild, t->rchild);
    }

    bool dfs(BiTNode *o, BiTNode *t) {
        if (!o) {
            return false;
        }
        return check(o, t) || dfs(o->lchild, t) || dfs(o->rchild, t);
    }

    bool isSubtree(BiTNode *s, BiTNode *t) {
        return dfs(s, t);
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
    cout << boolalpha << sol.isSubtree(bt1, bt2);
    return 0;
}
// number of num1: 5
// 3 4 1 2 5
// number of num2: 5
// 1 4 2 3 5
// number of num3: 3
// 4 1 2
// number of num4: 3
// 1 4 2