#include <vector>
#include<algorithm>
#include<iostream>
#include<cstdlib>
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
    // 同21题目的方法
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
    srand(n);
    for (int i = 1; i <= n; i++){
        t = rand() % 10 + 1;
        nums.push_back(t);
    }
    ListNode *head;
    Solution sol;
    LinkList ll = sol.CreateList2(nums);
    ll = sol.swapPairs(ll);
    return 0;
}
/*给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。*/
// number of nums: 4
// 1 2 3 4