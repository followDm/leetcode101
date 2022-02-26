import java.util.Scanner;

public class LeetCode714 {
    public static void main(String[] args) {
        //一维整数数组
        LeetCode714 solution = new LeetCode714();
        Scanner scanner = new Scanner(System.in);
        
        int rows = 0;
        System.out.print("number of nums: ");
        rows = scanner.nextInt();
        int [] prices = new int[rows];
        for (int i = 1; i <= rows; i++){
            prices[i-1] = scanner.nextInt();
        }
        System.out.print("fee: ");
        rows = scanner.nextInt();
        solution.maxProfit(prices, rows);
        scanner.close();
    }
    public int maxProfit(int[] prices, int fee) {
        int n = prices.length;
        int sell = 0, buy = -prices[0];
        for (int i = 1; i < n; ++i) {
            sell = Math.max(sell, buy + prices[i] - fee);
            buy = Math.max(buy, sell - prices[i]);
        }
        return sell;
    }
}
// number of nums: 6
// 1 3 2 8 4 9
// pee: 2
// 8