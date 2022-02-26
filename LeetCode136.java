import java.util.Scanner;

public class LeetCode136 {
    public static void main(String[] args) {
        //一维整数数组
        LeetCode136 solution = new LeetCode136();
        Scanner scanner = new Scanner(System.in);
        
        int rows = 0;
        System.out.print("number of nums: ");
        rows = scanner.nextInt();
        int [] nums = new int[rows];
        for (int i = 1; i <= rows; i++){
            nums[i-1] = scanner.nextInt();
        }
        solution.singleNumber(nums);
        scanner.close();
    }
    public int singleNumber(int[] nums) {
        int single = 0;
        for (int num : nums) {
            single ^= num;
        }
        return single;
    }
}

/*给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// 利用异或的特点
// number of nums: 3
// 1 2 2
// 1