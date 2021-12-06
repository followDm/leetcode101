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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = (LinkList)malloc(sizeof(ListNode));
        ListNode* prev = preHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        prev->next = l1 == nullptr ? l2 : l1;

        return preHead->next;
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
    vector<int> nums1, nums2;
    int n = 0, t = 0;
    cout << "number of num1: ";
    cin >> n;
    srand(n);
    // 这里直接用随机数不符合要求，因为要求的是递增的
    int mat = 0;
    for (int i = 1; i <= n; i++){
        t = mat + rand() % 5 + 1;
        mat = t;
        nums1.push_back(t);
    }
    cout << "number of num2: ";
    cin >> n;
    srand(n);
    mat = 0;
    for (int i = 1; i <= n; i++){
        t = mat + rand() % 5 + 1;
        mat = t;
        nums2.push_back(t);
    }
    Solution sol;
    LinkList l1 = sol.CreateList2(nums1);
    LinkList l2 = sol.CreateList2(nums2);
    LinkList lRes = sol.mergeTwoLists(l1, l2);
    return 0;
}
/*将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 */
// number of nums1: 4
// 1 3 5 7
// number of nums1: 4
// 2 4 6 8