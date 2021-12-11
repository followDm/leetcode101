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
    ListNode* oddEvenList(LinkList& head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* evenHead = head->next;
        ListNode* odd = head;
        ListNode* even = evenHead;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
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
        // 这一题还是去了头结点吧
        head = head->next;
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
    sol.CreateList2(head, nums);
    sol.oddEvenList(head);
    return 0;
}
/*给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/odd-even-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// number of nums: 5
// 1 3 5 5 5
