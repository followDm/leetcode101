import java.util.Arrays;
import java.util.Scanner;

public class LeetCode188 {
    public static void main(String[] args) {
        //一维整数数组
        LeetCode188 solution = new LeetCode188();
        Scanner scanner = new Scanner(System.in);
        
        int rows = 0;
        System.out.print("number of nums: ");
        rows = scanner.nextInt();
        int [] prices = new int[rows];
        for (int i = 1; i <= rows; i++){
            prices[i-1] = scanner.nextInt();
        }
        System.out.print("k: ");
        rows = scanner.nextInt();
        solution.maxProfit(rows, prices);
        scanner.close();
    }
    public int maxProfit(int k, int[] prices) {
        if (prices.length == 0) {
            return 0;
        }

        int n = prices.length;
        k = Math.min(k, n / 2);
        int[] buy = new int[k + 1];
        int[] sell = new int[k + 1];

        buy[0] = -prices[0];
        sell[0] = 0;
        for (int i = 1; i <= k; ++i) {
            buy[i] = sell[i] = Integer.MIN_VALUE / 2;
        }

        for (int i = 1; i < n; ++i) {
            buy[0] = Math.max(buy[0], sell[0] - prices[i]);
            for (int j = 1; j <= k; ++j) {
                buy[j] = Math.max(buy[j], sell[j] - prices[i]);
                sell[j] = Math.max(sell[j], buy[j - 1] + prices[i]);   
            }
        }

        return Arrays.stream(sell).max().getAsInt();
    }
}
/*给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// number of days: 6
// 3 2 6 5 0 3
// number of k: 2
// 7
// number of days: 6
// 3 2 6 5 0 3
// number of k: 2
// 7