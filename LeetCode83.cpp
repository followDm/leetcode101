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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }

        ListNode* cur = head;
        while (cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }

        return head;
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
    int n = 0, t = 0;
    cout << "number of num: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        nums.push_back(t);
    }
    ListNode* head = (LinkList)malloc(sizeof(ListNode));
    Solution sol;
    sol.CreateList2(head, nums);
    sol.deleteDuplicates(head);
    return 0;
}
// number of nums: 5
// 1 3 5 5 5
