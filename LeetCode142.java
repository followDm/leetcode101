import java.util.Scanner;

public class LeetCode142{
    public static void main(String[] args) {
        LeetCode142 solution = new LeetCode142();
        Scanner scanner = new Scanner(System.in);
        int[] numbers1;
        int n = 0, m = 0;
        System.out.print("number of numbers1: ");
        m = scanner.nextInt();

        numbers1 = new int[m+n];
        for (int i = 1; i <= m; i++){
            numbers1[i-1] = scanner.nextInt();
        }
        System.out.println("pos: ");
        int pos = scanner.nextInt();
        //非递归解决
        ListNode L = new ListNode();
        //尾插；带头结点
        solution.CreateList2(L, numbers1, pos);
        solution.detectCycle(L.next);
        scanner.close();
    }
    ListNode CreateList2(ListNode L, int[] nums, int pos){
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

        s = L;
        i = 0;
        while(i < pos){
            s = s.next;
            i ++;
        }
        if(pos < 0){
            r.next = null;
        } else {
            r.next = s;
        }
        return L;
    }
    public ListNode detectCycle(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode slow = head, fast = head;
        while (fast != null) {
            slow = slow.next;
            if (fast.next != null) {
                fast = fast.next.next;
            } else {
                return null;
            }
            if (fast == slow) {
                ListNode ptr = head;
                while (ptr != slow) {
                    ptr = ptr.next;
                    slow = slow.next;
                }
                return ptr;
            }
        }
        return null;
    }
}
// number of numbers1: 3
// number of numbers2: 3
// 1 2 3
// 2 3 4