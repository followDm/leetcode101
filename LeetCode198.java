import java.util.Scanner;

public class LeetCode198{
    public static void main(String[] args) {
        LeetCode198 solution = new LeetCode198();
        Scanner scanner = new Scanner(System.in);

        System.out.print("number of nums: ");
        int n = scanner.nextInt();
        int[] nums = new int[n];
        
        for (int i = 1; i <= n; i++){
            nums[i-1] = scanner.nextInt();
        }
        // 房子的位置不是环形
        solution.rob(nums); 
        scanner.close();
    }

    public int rob(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int length = nums.length;
        if (length == 1) {
            return nums[0];
        }
        int first = nums[0], second = Math.max(nums[0], nums[1]);
        for (int i = 2; i < length; i++) {
            int temp = second;
            second = Math.max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
}

/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// number of nums: 5
// 2 7 9 3 1
// 12