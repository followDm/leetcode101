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
    
    int pathSum(BiTNode* root, int sum){
        return root ? pathSumStartWithRoot(root, sum) + pathSum(root->lchild, sum) + pathSum(root->rchild, sum) : 0;
    }
    int pathSumStartWithRoot(BiTNode* root, int sum){
        if(!root){
            return 0;
        }
        int count = root->data == sum ? 1 : 0;
        count += pathSumStartWithRoot(root->lchild, sum - root->data);
        count += pathSumStartWithRoot(root->rchild, sum - root->data);
        return count;
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
    cout << "number of target: ";
    cin >> target;
    Solution sol;
    BiTree bt = sol.PreInCreat(nums1, nums2, 1, n1, 1, n2);
    cout << sol.pathSum(bt, target);
    return 0;
}
// 不能让重复的值做连续的左子树和根结点
// number of nums1: 9
// 10 5 3 -2 3 2 1 -3 11
// number of nums1: 9
// -2 3 3 5 2 1 10 -3 11
// number of target: 8
// 3