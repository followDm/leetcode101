#include <vector>
#include<algorithm>
#include<cstdlib>
#include<iostream>
using namespace std;

// typedef struct ListNode{
//     int val;
//     struct ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// }ListNode, *LinkList;
typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* y) : val(x), next(y) {}
}ListNode, *LinkList;
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        int length = 0;
        ListNode* node = head;
        while (node != nullptr) {
            length++;
            node = node->next;
        }
        ListNode* dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode* prev = dummyHead, *curr = dummyHead->next;
            while (curr != nullptr) {
                ListNode* head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* next = nullptr;
                if (curr != nullptr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummyHead->next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
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
        // ?????????????????????????????????
        // head = head->next;
        return nullptr;
    }
};

int main(){
    vector<int> nums;
    int n = 0, t = 0;
    cout << "number of num: ";
    cin >> n;
    srand(n);
    for (int i = 1; i <= n; i++){
        t = rand() % 9 + 1;
        nums.push_back(t);
    }
    ListNode* head = (LinkList)malloc(sizeof(ListNode));
    Solution sol;
    // ??????????????????
    sol.CreateList2(head, nums);
    sol.sortList(head);
    return 0;
}
/*??????????????????????????head????????????????? ?????? ??????????????? ?????????????????? ???

?????????

??????????????O(n??log??n) ???????????????????????????????????????????????????????????????????????????

??????????????????LeetCode???
?????????https://leetcode-cn.com/problems/sort-list
??????????????????????????????????????????????????????????????????????????????????????????????????????*/
// ????????????????????????
// number of num: 5
// 1 2 3 5 5