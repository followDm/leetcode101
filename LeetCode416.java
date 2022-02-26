import java.util.Scanner;

public class LeetCode416{
    public static void main(String[] args) {
        LeetCode416 solution = new LeetCode416();
        Scanner scanner = new Scanner(System.in);

        System.out.print("number of nums: ");
        int n = scanner.nextInt();
        int[] nums = new int[n];
        
        for (int i = 1; i <= n; i++){
            nums[i-1] = scanner.nextInt();
        }
        //数组的值平均分开
        solution.canPartition(nums);
        scanner.close();
    }
    public boolean canPartition(int[] nums) {
        int n = nums.length;
        if (n < 2) {
            return false;
        }
        int sum = 0, maxNum = 0;
        for (int num : nums) {
            sum += num;
            maxNum = Math.max(maxNum, num);
        }
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target) {
            return false;
        }
        boolean[] dp = new boolean[target + 1];
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int j = target; j >= num; --j) {
                dp[j] |= dp[j - num];
            }
        }
        return dp[target];
    }
}
/*给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。*/
// 背包问题
// number of nums: 4
// 1 5 5 11
// true
// number of nums: 4
// 1 5 5 11
// true