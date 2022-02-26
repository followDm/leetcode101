import java.util.Scanner;

public class LeetCode21 {
    public static void main(String[] args) {
        //两个一维整数数组
        LeetCode21 solution = new LeetCode21();
        Scanner scanner = new Scanner(System.in);
        int[] numbers1, numbers2;
        int n = 0, m = 0;
        System.out.print("number of numbers1: ");
        m = scanner.nextInt();
        System.out.print("number of numbers2: ");
        n = scanner.nextInt();

        numbers1 = new int[m];
        for (int i = 1; i <= m; i++){
            numbers1[i-1] = scanner.nextInt();
        }
        numbers2 = new int[n];
        for (int i = 1; i <= n; i++){
            numbers2[i-1] = scanner.nextInt();
        }
        ListNode L1 = new ListNode();
        //尾插；带头结点
        solution.CreateList2(L1, numbers1);
        ListNode L2 = new ListNode();
        //尾插；带头结点
        solution.CreateList2(L2, numbers2);
        //合并两个链表
        solution.mergeTwoLists(L1.next, L2.next);
        scanner.close();
    }

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode prehead = new ListNode(-1);

        ListNode prev = prehead;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                prev.next = l1;
                l1 = l1.next;
            } else {
                prev.next = l2;
                l2 = l2.next;
            }
            prev = prev.next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        prev.next = l1 == null ? l2 : l1;

        return prehead.next;
    }

    ListNode CreateList2(ListNode L, int[] nums){
        int n = nums.length;
        ListNode s = new ListNode(),r = L;
        // r->val = nums[0];
        // int i = 1;
        int i = 0;
        while(i < n){
            s = new ListNode();
            s.val = nums[i++];
            r.next = s;
            r=s;
        }
        // 也可以r->next = nullptr;
        s.next = null;
        return L;
    }
}
/*将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 */
// number of nums1: 4
// 1 3 5 7
// number of nums1: 4
// 2 4 6 8
// number of nums1: 4
// 1 3 5 7
// number of nums1: 4
// 2 4 6 8