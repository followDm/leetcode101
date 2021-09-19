#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

typedef struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr){};
}ListNode, *LinkList;

class Solution {
private:
    ListNode * dummy;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        dummy = new ListNode(-1);
        dummy->next = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        auto tail = dummy->next;
        int ans=0;
        for(int i =1; tail; i++){
            if(rand() %i +1 ==1) ans = tail->val;
            tail = tail->next;
        }

        return ans;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution solution = Solution(head);

    // getRandom()方法应随机返回1,2,3中的一个，保证每个元素被返回的概率相等。
    cout << solution.getRandom();
    return 0;
}
