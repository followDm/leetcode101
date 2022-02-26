import java.util.Scanner;

public class LeetCode338 {
    public static void main(String[] args) {
        //一个整数
        LeetCode338 solution = new LeetCode338();
        Scanner scanner = new Scanner(System.in);

        System.out.print("target: ");
        int n = scanner.nextInt();
        //比特位计数
        solution.countBits(n); 
        scanner.close();
    }
    public int[] countBits(int n) {
        int[] bits = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            bits[i] = bits[i & (i - 1)] + 1;
        }
        return bits;
    }
}
/*给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。*/
// 四种方法
// 动态规划加位运算
// target: 5
// [0,1,1,2,1,2]