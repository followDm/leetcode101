#include<array>
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
    bool check(BiTNode *p, BiTNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->data == q->data && check(p->lchild, q->rchild) && check(p->rchild, q->lchild);
    }
    bool isSymmetric(BiTNode* root) {
        return check(root, root);
    }
};

int main(){
    int n1 = 0, n2 = 0, t = 0;
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
    Solution sol;
    BiTree bt = sol.PreInCreat(nums1, nums2, 1, n1, 1, n2);
    cout << boolalpha << sol.isSymmetric(bt);
    return 0;
}
// number of nums1: 7
// 1 2 3 4 2 4 3
// number of nums1: 7
// 3 2 4 1 4 2 3
// true