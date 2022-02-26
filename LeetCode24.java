import java.util.Scanner;

public class LeetCode24 {
    public static void main(String[] args) {
        // 一维整数数组
        LeetCode24 solution = new LeetCode24();
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
        //相邻交换
        solution.swapPairs(L.next);
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
    public ListNode swapPairs(ListNode head) {
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        ListNode temp = dummyHead;
        while (temp.next != null && temp.next.next != null) {
            ListNode node1 = temp.next;
            ListNode node2 = temp.next.next;
            temp.next = node2;
            node1.next = node2.next;
            node2.next = node1;
            temp = node1;
        }
        return dummyHead.next;
    }
}

/*给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。*/
// number of nums: 4
// 1 2 3 4
// number of nums: 4
// 1 2 3 4