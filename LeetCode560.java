import java.util.HashMap;
import java.util.Scanner;

public class LeetCode560{
    public static void main(String[] args) {
        //一维整数数组
        LeetCode560 solution = new LeetCode560();
        Scanner scanner = new Scanner(System.in);
        
        int rows = 0;
        System.out.print("number of nums: ");
        rows = scanner.nextInt();
        int [] grid = new int[rows];
        for (int i = 1; i <= rows; i++){
            grid[i-1] = scanner.nextInt();
        }
        System.out.print("target: ");
        int target = scanner.nextInt();
        //哈希加前缀
        solution.subarraySum(grid, target);
        scanner.close();
    }
    public int subarraySum(int[] nums, int k) {
        int count = 0, pre = 0;
        HashMap < Integer, Integer > mp = new HashMap < > ();
        mp.put(0, 1);
        for (int i = 0; i < nums.length; i++) {
            pre += nums[i];
            if (mp.containsKey(pre - k)) {
                count += mp.get(pre - k);
            }
            mp.put(pre, mp.getOrDefault(pre, 0) + 1);
        }
        return count;
    }
}

/*给你一个整数数组 nums 和一个整数 k ，请你统计并返回该数组中和为 k 的连续子数组的个数。*/
// 前缀和
// number of nums: 3
// 2 2 2
// target: 2
// 3
// number of nums: 8
// 3 4 7 2 -3 1 4 2
// target: 7
// 4