import java.util.Scanner;

public class LeetCode650 {
    public static void main(String[] args) {
        //一个整数
        LeetCode650 solution = new LeetCode650();
        Scanner scanner = new Scanner(System.in);

        System.out.print("nums: ");
        int n = scanner.nextInt();
        //只有两个健的键盘
        solution.minSteps(n); 
        scanner.close();
    }
    public int minSteps(int n) {
        int[] f = new int[n + 1];
        
        double h = Math.sqrt(n);
        for (int i = 2; i <= n; ++i) {
            f[i] = i;
            for (int j = 2; j <= h; ++j) {
                if (i % j == 0) {
                    f[i] = f[j] + f[i/j];
                    break;
                }
            }
        }
        return f[n];
    }
}
/*最初记事本上只有一个字符 'A' 。你每次可以对这个记事本进行两种操作：

Copy All（复制全部）：复制这个记事本中的所有字符（不允许仅复制部分字符）。
Paste（粘贴）：粘贴 上一次 复制的字符。
给你一个数字 n ，你需要使用最少的操作次数，在记事本上输出 恰好 n 个 'A' 。返回能够打印出 n 个 'A' 的最少操作次数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/2-keys-keyboard
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// num: 3
// 3
// num: 3
// 3