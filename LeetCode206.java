import java.util.Scanner;

public class LeetCode206 {
    public static void main(String[] args) {
        // 一维整数数组
        LeetCode206 solution = new LeetCode206();
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
        solution.reverseList(L.next);
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
    public ListNode reverseList(ListNode head) {
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
}

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
// 反转一个链表
// number of nums: 4
// 1 2 3 4