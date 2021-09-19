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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
    LinkList CreateList2(LinkList &head1, LinkList &head2, vector<int> nums1, vector<int> nums2, vector<int> pub){
        int n = pub.size();
        LinkList L=(LinkList)malloc(sizeof(ListNode));
        ListNode *s,*r=L;
        // r->val = nums1[0];
        // i = 1;
        int i = 0;
        while(i < n){
            s=(ListNode*)malloc(sizeof(ListNode));
            s->val=pub[i++];
            r->next=s;
            r=s;
        }
        // 也可以r->next = nullptr;
        s->next = nullptr;
        //-------------------------------//
        n = nums1.size();
        r = head1;
        i = 0;
        while(i < n){
            s=(ListNode*)malloc(sizeof(ListNode));
            s->val=nums1[i++];
            r->next=s;
            r=s;
        }
        s->next = L->next;

        //-------------------------------//
        n = nums2.size();
        r = head2;
        i = 0;
        while(i < n){
            s=(ListNode*)malloc(sizeof(ListNode));
            s->val=nums2[i++];
            r->next=s;
            r=s;
        }
        s->next = L->next;

        return nullptr;
    }
};

int main(){
    vector<int> nums1, nums2, pub;
    int n = 0, t = 0;
    cout << "number of num1: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        nums1.push_back(t);
    }
    cout << "number of num2: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        nums2.push_back(t);
    }
    cout << "number of public: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        pub.push_back(t);
    }
    ListNode *head2 = (LinkList)malloc(sizeof(ListNode));
    ListNode* head1 = (LinkList)malloc(sizeof(ListNode));
    Solution sol;
    sol.CreateList2(head1, head2, nums1, nums2, pub);
    sol.getIntersectionNode(head1, head2);
    return 0;
}
// number of nums1: 4
// 1 3 5 7
// number of nums1: 4
// 2 4 6 8
// number of public: 1
// 1