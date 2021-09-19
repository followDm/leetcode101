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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow) {
                ListNode *ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
    LinkList CreateList2(LinkList &L, vector<int> nums, int pos){
        int n = nums.size();
        //L=(LinkList)malloc(sizeof(ListNode));
        ListNode *s,*r=L;
        int i = 1;
        while(i < n){
            s=(ListNode*)malloc(sizeof(ListNode));
            s->val=nums[i++];
            r->next=s;
            r=s;
        }
        s = L;
        i = 0;
        while(i < pos){
            s = s->next;
            i ++;
        }
        if(pos < 0){
            r->next = NULL;
        } else {
            r->next = s;
        }
        return L;
    }
};

int main(){
    vector<int> nums;
    int n = 0, t = 0, pos = 0;
    cout << "number of nums: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        nums.push_back(t);
    }
    cout << "number of pos: ";
    cin >> pos;
    ListNode *head;
    head = (ListNode*)malloc(sizeof(ListNode));
    head->val = nums[0];
    Solution sol;
    LinkList ll = sol.CreateList2(head, nums, pos);
    cout << sol.detectCycle(head)->val;
    return 0;
}

/**
 * 输入：head = [3,2,0,-4], pos = 1
 * 输出：返回索引为 1 的链表节点
 * 解释：链表中有一个环，其尾部连接到第二个节点。
*/
// number of nums: 4
// 1 2 3 4
// number of pos: 1
// 2
