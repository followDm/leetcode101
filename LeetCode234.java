import java.util.Scanner;

public class LeetCode234 {
    public static void main(String[] args) {
        // 一维整数数组
        LeetCode234 solution = new LeetCode234();
        Scanner scanner = new Scanner(System.in);

        int rows = 0;
        System.out.print("number of nums: ");
        rows = scanner.nextInt();
        int[] grid = new int[rows];
        for (int i = 1; i <= rows; i++) {
            grid[i - 1] = scanner.nextInt();
        }
        //非递归解决
        ListNode L = new ListNode();
        //尾插；带头结点
        solution.CreateList2(L, grid);
        //是否回文链表
        solution.isPalindrome(L.next);
        scanner.close();
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
    public boolean isPalindrome(ListNode head) {
        if (head == null) {
            return true;
        }

        // 找到前半部分链表的尾节点并反转后半部分链表
        ListNode firstHalfEnd = endOfFirstHalf(head);
        ListNode secondHalfStart = reverseList(firstHalfEnd.next);

        // 判断是否回文
        ListNode p1 = head;
        ListNode p2 = secondHalfStart;
        boolean result = true;
        while (result && p2 != null) {
            if (p1.val != p2.val) {
                result = false;
            }
            p1 = p1.next;
            p2 = p2.next;
        }        

        // 还原链表并返回结果
        firstHalfEnd.next = reverseList(secondHalfStart);
        return result;
    }

    private ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode nextTemp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    private ListNode endOfFirstHalf(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        while (fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }
}
/*给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。*/
/**
 * 我把创建的头结点删了
 */
// number of nums: 5
// 1 3 5 3 1
// number of nums: 5
// 1 3 5 3 1