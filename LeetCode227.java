import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class LeetCode227 {
    public static void main(String[] args) {
        //一维整数数组
        LeetCode227 solution = new LeetCode227();
        Scanner scanner = new Scanner(System.in);
        String m;
        System.out.print("string m: ");
        m = scanner.nextLine();
        //基本计算器
        solution.calculate(m);
        scanner.close();
    }
    public int calculate(String s) {
        Deque<Integer> stack = new LinkedList<Integer>();
        //作用类似与头结点，我自己觉得
        char preSign = '+';
        int num = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (Character.isDigit(s.charAt(i))) {
                num = num * 10 + s.charAt(i) - '0';
            }
            if (!Character.isDigit(s.charAt(i)) && s.charAt(i) != ' ' || i == n - 1) {
                switch (preSign) {
                    case '+':
                        stack.push(num);
                        break;
                    case '-':
                        stack.push(-num);
                        break;
                    case '*':
                        stack.push(stack.pop() * num);
                        break;
                    default:
                        stack.push(stack.pop() / num);
                }
                preSign = s.charAt(i);
                num = 0;
            }
        }
        int ans = 0;
        while (!stack.isEmpty()) {
            ans += stack.pop();
        }
        return ans;
    }
}

/*给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

整数除法仅保留整数部分。*/
// string: 5 * 4 / 2 - 3 + 1
// 8