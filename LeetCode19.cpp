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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = head;
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0; i < n; ++i) {
            first = first->next;
        }
        while (first->next != nullptr) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }

    LinkList CreateList2(LinkList &head, vector<int> nums){
        int n = nums.size();
        ListNode *s,*r=head;
        int i = 0;
        while(i < n){
            s=(ListNode*)malloc(sizeof(ListNode));
            s->val=nums[i++];
            r->next=s;
            r=s;
        }
        s->next = nullptr;
        // 有了它就等于不要头结点
        // head = head->next;
        return nullptr;
    }
};

int main(){
    vector<int> nums;
    int n = 0, t = 0, target;
    cout << "number of num: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        nums.push_back(t);
    }
    cout << "target: ";
    cin >> target;
    ListNode* head = (LinkList)malloc(sizeof(ListNode));
    Solution sol;
    sol.CreateList2(head, nums);
    sol.removeNthFromEnd(head, target);
    return 0;
}

// number of num: 5
// 1 2 3 5 5
// target: 2