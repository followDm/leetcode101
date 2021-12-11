#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* y) : val(x), next(y) {}
}ListNode, *LinkList;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }

        ListNode* cur = head;
        ListNode* tem;
        while (cur->next) {
            if (cur->val == cur->next->val) {
                tem = cur->next;
                cur->next = cur->next->next;
                // 小小的一步就是释放空间了
                free(tem);
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
    vector<int> nums = {1, 2, 3, 3, 4, 5, 5};
    int n = 0, t = 0;
    // 这里输入也不想输入了，直接定义好吧
    ListNode* head = (LinkList)malloc(sizeof(ListNode));
    Solution sol;
    sol.CreateList2(head, nums);
    sol.deleteDuplicates(head);
    return 0;
}
/*存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次 。

返回同样按升序排列的结果链表。*/
// number of nums: 5
// 1 3 5 5 5
