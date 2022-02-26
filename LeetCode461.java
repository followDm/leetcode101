import java.util.Scanner;

public class LeetCode461 {
    public static void main(String[] args) {
        //两个字符串
        LeetCode461 solution = new LeetCode461();
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("num m: ");
        int m = scanner.nextInt();
        System.out.print("num n: ");
        int n = scanner.nextInt();
        //汉明距离
        solution.hammingDistance(m, n);
        scanner.close();
    }
    public int hammingDistance(int x, int y) {
        int s = x ^ y, ret = 0;
        while (s != 0) {
            s &= s - 1;
            ret++;
        }
        return ret;
    }
}
/*两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。

给你两个整数 x 和 y，计算并返回它们之间的汉明距离。*/
// 异或一下就行了
// n: 1
// t: 4
// 2