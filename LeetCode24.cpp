#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

typedef struct ListNode{
    int val;
    struct ListNode *next;
}ListNode, *LinkList;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = (LinkList)malloc(sizeof(ListNode));
        dummyHead->next = head;
        ListNode* temp = dummyHead;
        while (temp->next != nullptr && temp->next->next != nullptr) {
            ListNode* node1 = temp->next;
            ListNode* node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return dummyHead->next;
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
    for (int i = 1; i <= n; i++){
        cin >> t;
        nums.push_back(t);
    }
    ListNode *head;
    Solution sol;
    LinkList ll = sol.CreateList2(nums);
    sol.swapPairs(ll);
    return 0;
}
// number of nums: 4
// 1 2 3 4