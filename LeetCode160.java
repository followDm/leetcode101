import java.util.Scanner;

public class LeetCode160 {
    public static void main(String[] args) {
        // 一维整数数组
        LeetCode160 solution = new LeetCode160();
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

        System.out.print("number of public: ");
        n = scanner.nextInt();
        int[] publicNum = new int[n];
        for (int i = 1; i <= n; i++){
            publicNum[i-1] = scanner.nextInt();
        }
        //非递归解决
        ListNode L1 = new ListNode();
        ListNode L2 = new ListNode();
        //尾插；带头结点
        solution.CreateList2(L1, numbers1, L2, numbers2, publicNum);
        solution.getIntersectionNode(L1.next, L2.next);
        scanner.close();
    }

    ListNode CreateList2(ListNode L1, int[] nums1, ListNode L2, int[] nums2, int[] pub){
        int n = pub.length;
        ListNode s = new ListNode();
        ListNode p = new ListNode();
        ListNode r = p;
        int i = 0;
        while(i < n){
            s = new ListNode();
            s.val = nums1[i++];
            r.next = s;
            r=s;
        }
        s.next = null;

        n = nums1.length;
        s = new ListNode();
        r = L1;
        i = 0;
        while(i < n){
            s = new ListNode();
            s.val = nums1[i++];
            r.next = s;
            r=s;
        }
        s.next = p.next;

        n = nums2.length;
        s = new ListNode();
        r = L2;
        i = 0;
        while(i < n){
            s = new ListNode();
            s.val = nums2[i++];
            r.next = s;
            r=s;
        }
        s.next = p.next;

        return null;
    }
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) {
            return null;
        }
        ListNode pA = headA, pB = headB;
        while (pA != pB) {
            pA = pA == null ? headB : pA.next;
            pB = pB == null ? headA : pB.next;
        }
        return pA;
    }
}

/*给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。*/
// number of nums1: 4
// 1 3 5 7
// number of nums2: 4
// 2 4 6 8
// number of public: 1
// 1
// number of nums1: 4
// 1 3 5 7
// number of nums2: 4
// 2 4 6 8
// number of public: 1
// 1