#include<array>
#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;

typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

class Solution {
public:
    BiTree PreInCreat(int A[], int B[], int l1, int h1, int l2, int h2) {
        BiTree root= (BiTNode*) malloc (sizeof (BiTNode) ) ;
        root->data=A[l1];
        int i = 0;
        for (i = l2; B [i] != root->data; i++);
        //子树长度
        int llen = i - l2;
        int rlen = h2 - i;
        if (llen)
            root->lchild = PreInCreat(A, B, l1+1, l1+llen, l2, l2+llen-1);
        else
            root->lchild = nullptr;

        if (rlen)
            root->rchild = PreInCreat(A, B, h1-rlen+1, h1, h2-rlen+1, h2);
        else
            root->rchild = nullptr;
        return root;
    }
    vector<BiTNode*> deiNodes(BiTNode* root, vector<int>& to_delete) {
        vector<BiTNode*> forest;
        unordered_set<int> diet(to_delete.begin(), to_delete.end());
        root = helper(root, diet, forest);
        if (root) {
        forest.push_back(root);
        }
        return forest;
    }

    BiTNode* helper(BiTNode* root, unordered_set<int> & diet, vector<BiTNode*> &forest) {
        if (!root) {
            return root;
        }
        root->lchild = helper(root->lchild, diet, forest);
        root->rchild = helper(root->rchild, diet, forest);
        if(diet.count(root->data)) {
            if (root->lchild) {
                forest.push_back(root->lchild);
            }
            if (root->rchild) {
                forest.push_back(root->rchild);
            }
            root = nullptr;
        }
        return root;
    }
};
int main(){
    int n1 = 0, n2 = 0, t = 0, target = 0;
    cout << "number of num1: ";
    cin >> n1;
    int nums1[n1+1];
    for (int i = 1; i <= n1; i++){
        cin >> t;
        nums1[i] = t;
    }
    cout << "number of num2: ";
    cin >> n2;
    int nums2[n2+1];
    for (int i = 1; i <= n2; i++){
        cin >> t;
        nums2[i] = t;
    }
    cout << "number of dels: ";
    cin >> target;
    vector<int> del;
    for (int i = 1; i <= target; i++){
        cin >> t;
        del.push_back(t);
    }
    Solution sol;
    BiTree bt = sol.PreInCreat(nums1, nums2, 1, n1, 1, n2);
    sol.deiNodes(bt, del);
    return 0;
}
// number of num1: 7
// 1 2 4 5 3 6 7
// number of num2: 7
// 4 2 5 1 6 3 7
// number of dels: 2
// 3 5