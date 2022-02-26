import java.util.Scanner;

public class LeetCode769 {
    public static void main(String[] args) {
        //一维整数数组
        LeetCode769 solution = new LeetCode769();
        Scanner scanner = new Scanner(System.in);
        
        int rows = 0;
        System.out.print("number of nums: ");
        rows = scanner.nextInt();
        int [] grid = new int[rows];
        for (int i = 1; i <= rows; i++){
            grid[i-1] = scanner.nextInt();
        }
        solution.maxChunksToSorted(grid);
        scanner.close();
    }
    public int maxChunksToSorted(int[] arr) {
        int ans = 0, max = 0;
        for (int i = 0; i < arr.length; ++i) {
            max = Math.max(max, arr[i]);
            if (max == i) ans++;
        }
        return ans;
    }
}
/*数组arr是[0, 1, ..., arr.length - 1]的一种排列，我们将这个数组分割成几个“块”，并将这些块分别进行排序。之后再连接起来，使得连接的结果和按升序排序后的原数组相同。

我们最多能将数组分成多少块？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-chunks-to-make-sorted
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// 可以利用元素值和位置的关系
// number of nums: 5
// 4 0 1 2 3
// 1
// number of nums: 5
// 4 0 1 2 3
// 1