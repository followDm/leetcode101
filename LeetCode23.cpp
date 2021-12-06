#include<queue>
#include<vector>
#include<iostream>
using namespace std;
typedef struct ListNode{
    int val;
    struct ListNode *next;
}ListNode, *LinkList;

class Solution {
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) 
                q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top(); 
            q.pop();
            tail->next = f.ptr; 
            tail = tail->next;
            if (f.ptr->next) 
                q.push({f.ptr->next->val, f.ptr->next});
        }
        // tail->next = NULL;
        return head.next;
    }
    LinkList CreateList2(vector<int> nums){
        int n = nums.size();
        LinkList L=(LinkList)malloc(sizeof(ListNode));
        L->val = nums[0];
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
    vector<int> num;
    vector<LinkList> lists;
    Solution sol;
    // 因为觉得自己输入比较麻烦，最后直接生成了。既然自动生成就来复杂点
    for (int i = 1; i <= 6; ++i){
        for (int j = 0; j< i; ++j){
            num.push_back(j + 1);
        }
        lists.push_back(sol.CreateList2(num));
        num.clear();
    }
    LinkList ll = sol.mergeKLists(lists);
    return 0;
}

/*给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。*/