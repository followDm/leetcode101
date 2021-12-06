#include <vector>
#include<algorithm>
#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
}ListNode, *LinkList;

class Solution {
public:
    // ListNode* reverseList(ListNode* head) {
    //     if (!head || !head->next) {
    //         return head;
    //     }
    //     ListNode* newHead = reverseList(head->next);
    //     head->next->next = head;
    //     head->next = nullptr;
    //     return newHead;
    // }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    LinkList CreateList2(LinkList &L, vector<int> nums){
        int n = nums.size();
        // L=(LinkList)malloc(sizeof(ListNode));
        ListNode *s,*r=L;
        int i = 1;
        while(i < n){
            s=(ListNode*)malloc(sizeof(ListNode));
            s->val=nums[i++];
            r->next=s;
            r=s;
        }
        r->next = nullptr;
        return L;
    }
};

int main(){
    vector<int> nums;
    int n = 0, t = 0;
    cout << "number of nums: ";
    cin >> n;
    srand(n);
    for (int i = 1; i <= n; i++){
        t = rand() % 10 + 1;
        nums.push_back(t);
    }
    ListNode *head;
    head = (ListNode*)malloc(sizeof(ListNode));
    head->val = nums[0];
    Solution sol;
    LinkList ll = sol.CreateList2(head, nums);
    sol.reverseList(ll);
    return 0;
}
// number of nums: 4
// 1 2 3 4