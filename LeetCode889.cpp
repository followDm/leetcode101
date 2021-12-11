#include<array>
#include<vector>
#include<iostream>
using namespace std;

typedef struct TreeNode{
	int val;
	struct TreeNode *left,*right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
}TreeNode, *NodeTree;

class Solution {
public:
    vector<int> pre, post;
    TreeNode* constructFromPrePost(vector<int> pre, vector<int> post) {
        this->pre = pre;
        this->post = post;
        return make(0, 0, pre.size());
    }

    TreeNode* make(int i0, int i1, int N) {
        if (N == 0) 
            return nullptr;
        TreeNode* root = new TreeNode(pre[i0]);
        if (N == 1) 
            return root;
        int L = 1;
        for (; L < N; ++L)
            if (post[i1 + L-1] == pre[i0 + 1])
                break;

        root->left = make(i0+1, i1, L);
        root->right = make(i0+L+1, i1+L, N-1-L);
        return root;
    }
};
int main(){
    int n1 = 0, n2 = 0, t = 0, target = 0, p = 0, q = 0;
    cout << "number of nodes: ";
    cin >> n1;
    cout << "preorder: ";
    vector<int> nums1;
    for (int i = 1; i <= n1; i++){
        cin >> t;
        nums1.push_back(t);
    }
    cout << "postorder: ";
    vector<int> nums2;
    for (int i = 1; i <= n1; i++){
        cin >> t;
        nums2.push_back(t);
    }
    Solution sol;
    TreeNode* res = sol.constructFromPrePost(nums1, nums2);
    return 0;
}
/*返回与给定的前序和后序遍历匹配的任何二叉树。

 pre 和 post 遍历中的值是不同的正整数。*/
//先序和后序？
// number of num1: 7
// 1 2 3 4 5 6 7
// number of num2: 7
// 4 5 2 6 7 3 1