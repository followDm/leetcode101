import java.util.PriorityQueue;
import java.util.Scanner;

public class LeetCode23 {
    public static void main(String[] args) {
        // 一维整数数组
        LeetCode23 solution = new LeetCode23();
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
    
    class Status implements Comparable<Status> {
        int val;
        ListNode ptr;

        Status(int val, ListNode ptr) {
            this.val = val;
            this.ptr = ptr;
        }

        public int compareTo(Status status2) {
            return this.val - status2.val;
        }
    }

    PriorityQueue<Status> queue = new PriorityQueue<Status>();

    public ListNode mergeKLists(ListNode[] lists) {
        for (ListNode node: lists) {
            if (node != null) {
                queue.offer(new Status(node.val, node));
            }
        }
        ListNode head = new ListNode(0);
        ListNode tail = head;
        while (!queue.isEmpty()) {
            Status f = queue.poll();
            tail.next = f.ptr;
            tail = tail.next;
            if (f.ptr.next != null) {
                queue.offer(new Status(f.ptr.next.val, f.ptr.next));
            }
        }
        return head.next;
    }
}
/*给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。*/
// 优先队列。英雄所见略同，我也觉得这个难