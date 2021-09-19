#include<array>
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;

typedef struct TreeNode{
	int val;
	struct TreeNode *left,*right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    //TreeNode() : nullptr, left(nullptr), right(nullptr){};
}TreeNode, *NodeTree;

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
    LinkList CreateList2(LinkList &L, vector<int> nums){
        int n = nums.size();
        
        ListNode *s,*r=L;
        int i = 1;
        while(i < n){
            s=(ListNode*)malloc(sizeof(ListNode));
            s->val=nums[i++];
            r->next=s;
            r=s;
        }
        r->next = NULL;
        return L;
    }    
};
int main(){
    vector<int> nums;
    int n = 0, t = 0;
    cout << "number of nums: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        nums.push_back(t);
    }
    ListNode *head;
    head = (ListNode*)malloc(sizeof(ListNode));
    head->val = nums[0];
    Solution sol;
    LinkList ll = sol.CreateList2(head, nums);
    NodeTree nt = sol.sortedListToBST(head);
    return 0;
}
// number of nums: 5
// -10 -3 0 5 9