import java.util.Scanner;

public class LeetCode241 {
    public static void main(String[] args) {
        //两个字符串
        LeetCode241 solution = new LeetCode241();
        Scanner scanner = new Scanner(System.in);
        
        String n, m;
        System.out.print("string m: ");
        m = scanner.nextLine();
        scanner.close();
    }
}
/*给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。

示例 1:

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/different-ways-to-add-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// target: 2*3-2
// [2,4]