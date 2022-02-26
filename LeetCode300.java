import java.util.Scanner;


public class LeetCode300{
    public static void main(String[] args) {
        LeetCode300 solution = new LeetCode300();
        Scanner scanner = new Scanner(System.in);
        
        int rows = 0;
        System.out.print("number of nums: ");
        rows = scanner.nextInt();
        int[] nums = new int[rows];
        for (int i = 1; i <= rows; i++){
            nums[i-1] = scanner.nextInt();
        }
        solution.lengthOfLIS(nums);
        scanner.close();
    }

    public int lengthOfLIS(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        int[] dp = new int[nums.length];
        dp[0] = 1;
        int maxans = 1;
        for (int i = 1; i < nums.length; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            maxans = Math.max(maxans, dp[i]);
        }
        return maxans;
    }
}
/*给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// 子序列问题
// 按照 LeetCode 的习惯，子序列（subsequence）不必连续，子数组（subarray）或子字符串（substring）必须连续
// number of nums: 6
// 0 1 0 2 0 3
// 4
//按照 LeetCode 的习惯，子序列（subsequence）不必连续，子数组（subarray）或子字符串（substring）必须连续
// number of nums: 6
// 0 1 0 2 0 3
// 4