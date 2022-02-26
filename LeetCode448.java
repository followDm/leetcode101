import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class LeetCode448 {
    public static void main(String[] args) {
        //一维整数数组
        LeetCode448 solution = new LeetCode448();
        Scanner scanner = new Scanner(System.in);
        
        int rows = 0;
        System.out.print("number of nums: ");
        rows = scanner.nextInt();
        int [] nums = new int[rows];
        for (int i = 1; i <= rows; i++){
            nums[i-1] = scanner.nextInt();
        }
        //一到N中没有出现的数字
        //用数组建立桶
        solution.findDisappearedNumbers(nums);
        scanner.close();
    }
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length;
        for (int num : nums) {
            int x = (num - 1) % n;
            nums[x] += n;
        }
        List<Integer> ret = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                ret.add(i + 1);
            }
        }
        return ret;
    }
}
/*给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// 主要用了桶，什么加n和减都是判断出现了没
// 利用原数组找没有出现的
// number of nums: 7
// 1 2 3 4 5 6 4
// [7]