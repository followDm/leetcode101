import java.util.Scanner;

public class LeetCode474{
    public static void main(String[] args) {
        LeetCode474 solution = new LeetCode474();
        Scanner scanner = new Scanner(System.in);

        System.out.print("number of strs: ");
        int n = scanner.nextInt();
        String[] strs = new String[n];
        
        for (int i = 1; i <= n; i++){
            strs[i-1] = scanner.next();
        }
        System.out.print("number of zeros: ");
        int m = scanner.nextInt();
        System.out.print("number of ones: ");
        n = scanner.nextInt();
        solution.findMaxForm(strs, m, n);
        scanner.close();
    }
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] dp = new int[m + 1][n + 1];
        int length = strs.length;
        for (int i = 0; i < length; i++) {
            int[] zerosOnes = getZerosOnes(strs[i]);
            int zeros = zerosOnes[0], ones = zerosOnes[1];
            for (int j = m; j >= zeros; j--) {
                for (int k = n; k >= ones; k--) {
                    //这里因为是逆序的，其实最后一趟没必要完整的走一遍，因为只需要dp[m][n];
                    dp[j][k] = Math.max(dp[j][k], dp[j - zeros][k - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }

    public int[] getZerosOnes(String str) {
        int[] zerosOnes = new int[2];
        int length = str.length();
        for (int i = 0; i < length; i++) {
            zerosOnes[str.charAt(i) - '0']++;
        }
        return zerosOnes;
    }
}
/*给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。

如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ones-and-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
/*经典的背包问题可以使用二维动态规划求解，两个维度分别是物品和容量。这道题有两种容量，因此需要使用三维动态规划求解，三个维度分别是字符串、00 的容量和 11 的容量。*/
// 零一背包问题
// strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
// number of strs: 5
// 10 0001 111001 1 0
// number of zeros: 5
// number of ones: 3