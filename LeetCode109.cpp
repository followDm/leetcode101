#include<array>
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct TreeNode{
	int val;
	struct TreeNode *left,*right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
}TreeNode,*NodeTree;

typedef struct ListNode{
    int val;
    struct ListNode *next;
}ListNode, *LinkList;

class Solution {
public:
    int getLength(ListNode* head) {
        int ret = 0;
        for (; head != nullptr; ++ret, head = head->next);
        return ret;
    }

    TreeNode* buildTree(ListNode*& head, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right + 1) / 2;
        TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
        root->left = buildTree(head, left, mid - 1);
        root->val = head->val;
        head = head->next;
        root->right = buildTree(head, mid + 1, right);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int length = getLength(head);
        return buildTree(head, 0, length - 1);
    }
    LinkList CreateList2(vector<int> nums){
        int n = nums.size();
        ListNode* L=(LinkList)malloc(sizeof(ListNode));
        ListNode *s,*r=L;
        r->val = nums[0];
        int i = 1;
        // int i = 0;
        while(i < n){
            s=(ListNode*)malloc(sizeof(ListNode));
            s->val=nums[i++];
            r->next=s;
            r=s;
        }
        // 也可以r->next = nullptr;
        s->next = nullptr;
        return L;
    }   
};
int main(){
    vector<int> nums;
    int n = 0, t = 0;
    cout << "number of nums: ";
    cin >> n;
    srand(n);
    int mat = 0;
    for (int i = 1; i <= n; i++){
        t = mat + rand() % 5 + 1;
        mat = t;
        nums.push_back(t);
    }
    Solution sol;
    LinkList ll = sol.CreateList2(nums);
    TreeNode* nt = sol.sortedListToBST(ll);
    return 0;
}
/*给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// number of nums: 5
// -10 -3 0 5 9