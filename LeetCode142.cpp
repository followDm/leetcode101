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

/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// number of nums: 4
// 1 2 3 4
// number of pos: 1
// 2
