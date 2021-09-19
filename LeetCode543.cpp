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
        //l1, h1为先序的第一和最后一个结点下标，l2,h2为中序的第一和最后一个结点下标
        //初始调用时，l1=l2=1, h1=h2=n
        //建根结点
        BiTree root= (BiTNode*) malloc (sizeof (BiTNode) ) ;
        root->data=A[l1];
        //根结点在中序序列中的划分
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
    int diameterOfBinaryTree(BiTNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
    int ans;
    int depth(BiTNode* rt){
        if (rt == NULL) {
            return 0; // 访问到空节点了，返回0
        }
        int L = depth(rt->lchild); // 左儿子为根的子树的深度
        int R = depth(rt->rchild); // 右儿子为根的子树的深度
        ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
        return max(L, R) + 1; // 返回该节点为根的子树的深度
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
    cout << sol.diameterOfBinaryTree(bt);
    return 0;
}
// number of nums1: 5
// 3 9 20 15 7
// number of nums1: 5
// 9 3 15 20 7
// 3