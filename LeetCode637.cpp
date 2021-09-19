#include<array>
#include<vector>
#include<queue>
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
    vector<double> averageOfLevels(BiTNode* root) {
        auto averages = vector<double>();
        auto q = queue<BiTNode*>();
        q.push(root);
        while (!q.empty()) {
            double sum = 0;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                sum += node->data;
                auto left = node->lchild, right = node->rchild;
                if (left != nullptr) {
                    q.push(left);
                }
                if (right != nullptr) {
                    q.push(right);
                }
            }
            averages.push_back(sum / size);
        }
        return averages;
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
    Solution sol;
    BiTree bt = sol.PreInCreat(nums1, nums2, 1, n1, 1, n2);
    vector<double> res = sol.averageOfLevels(bt);
    t = res.size();
    cout << "[";
    for (int i = 0; i < t - 1; i++){
        cout << res.at(i) << ",";
    }
    cout << res.at(t - 1) << "]";
    
    return 0;
}
// number of num1: 5
// 3 9 20 15 7
// number of num2: 5
// 9 3 15 20 7
// [3,14.5,11]