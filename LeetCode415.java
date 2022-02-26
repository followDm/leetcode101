import java.util.Scanner;

public class LeetCode415 {
    public static void main(String[] args) {
        //两个字符串
        LeetCode415 solution = new LeetCode415();
        Scanner scanner = new Scanner(System.in);
        
        String n, m;
        System.out.print("string m: ");
        m = scanner.nextLine();
        System.out.print("string n: ");
        n = scanner.nextLine();
        //字符串数字相加
        solution.addStrings(m, n);
        scanner.close();
    }
    public String addStrings(String num1, String num2) {
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        StringBuffer ans = new StringBuffer();
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1.charAt(i) - '0' : 0;
            int y = j >= 0 ? num2.charAt(j) - '0' : 0;
            int result = x + y + add;
            ans.append(result % 10);
            add = result / 10;
            i--;
            j--;
        }
        // 计算完以后的答案需要翻转过来
        ans.reverse();
        return ans.toString();
    }
}
/*给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。

你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// s1: 123456789
// s2: 987654321
// 1111111110