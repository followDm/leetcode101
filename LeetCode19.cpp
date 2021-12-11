#include<vector>
#include<algorithm>
#include<cstdlib>
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
    ListNode* removeNthFromEnd(LinkList &head, int n) {
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
        ListNode* tem;
        tem = second->next;
        second->next = second->next->next;
        free(tem);
        // ListNode* ans = dummy->next;
        // delete dummy;
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
    int n = 0, t = 0, target;
    cout << "number of num: ";
    cin >> n;
    srand(n);
    for (int i = 1; i <= n; i++){
        t = rand() % 9 + 1;
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
/*给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。*/
// 好的办法是用栈和双指针
// 两个指针 first 和 second 同时对链表进行遍历，并且 first 比 second 超前 n 个节点。当 first 遍历到链表的末尾时，second 就恰好处于倒数第 n 个节点
// number of num: 5
// 1 2 3 5 5
// target: 2