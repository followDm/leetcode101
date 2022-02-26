import java.util.Scanner;

public class LeetCode309 {
    public static void main(String[] args) {
        //一维整数数组
        LeetCode309 solution = new LeetCode309();
        Scanner scanner = new Scanner(System.in);
        
        int rows = 0;
        System.out.print("number of nums: ");
        rows = scanner.nextInt();
        int [] prices = new int[rows];
        for (int i = 1; i <= rows; i++){
            prices[i-1] = scanner.nextInt();
        }
        //含冷冻期1天
        solution.maxProfit(prices);
        scanner.close();
    }
    public int maxProfit(int[] prices) {
        if (prices.length == 0) {
            return 0;
        }

        int n = prices.length;
        int f0 = -prices[0];
        int f1 = 0;
        int f2 = 0;
        for (int i = 1; i < n; ++i) {
            int newf0 = Math.max(f0, f2 - prices[i]);
            int newf1 = f0 + prices[i];
            int newf2 = Math.max(f1, f2);
            f0 = newf0;
            f1 = newf1;
            f2 = newf2;
        }

        return Math.max(f1, f2);
    }
}
/*给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// number of days: 5
// 1 2 3 0 2
// 3
// number of days: 5
// 1 2 3 0 2
// 3