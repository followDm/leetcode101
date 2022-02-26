import java.util.Scanner;

public class LeetCode172 {
    public static void main(String[] args) {
        //一个整数
        LeetCode172 solution = new LeetCode172();
        Scanner scanner = new Scanner(System.in);

        System.out.print("n: ");
        int n = scanner.nextInt();
        //阶乘后零的个数
        solution.trailingZeroes(n); 
        scanner.close();
    }
    public int trailingZeroes(int n) {
        int zeroCount = 0;
        while (n > 0) {
            n /= 5;
            zeroCount += n;
        }
        return zeroCount;
    }
}
/*给定一个整数 n ，返回 n! 结果中尾随零的数量。

提示 n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1*/
// n: 12
// 2