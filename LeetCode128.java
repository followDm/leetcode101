import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class LeetCode128 {
    public static void main(String[] args) {
        //一维整数数组
        LeetCode128 solution = new LeetCode128();
        Scanner scanner = new Scanner(System.in);
        
        int rows = 0;
        System.out.print("number of nums: ");
        rows = scanner.nextInt();
        int [] grid = new int[rows];
        for (int i = 1; i <= rows; i++){
            grid[i-1] = scanner.nextInt();
        }
        //可以组成的最长连续子序列
        solution.longestConsecutive(grid);
        scanner.close();
    }
    public int longestConsecutive(int[] nums) {
        Set<Integer> num_set = new HashSet<Integer>();
        for (int num : nums) {
            num_set.add(num);
        }

        int longestStreak = 0;

        for (int num : num_set) {
            if (!num_set.contains(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.contains(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = Math.max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
}

/*给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// 数组最长连续序列