import java.util.Scanner;

public class LeetCode382 {
    public static void main(String[] args) {
        // 一维整数数组
        LeetCode382 solution = new LeetCode382();
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
    
}


/*给定一个单链表，随机选择链表的一个节点，并返回相应的节点值。保证每个节点被选的概率一样。

进阶:
如果链表十分大且长度未知，如何解决这个问题？你能否使用常数级空间复杂度实现？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-random-node
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// 水库算法
// 官方没有代码，不知道哪里来的了