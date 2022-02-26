import java.util.Scanner;

public class LeetCode696 {
    public static void main(String[] args) {
        //一维整数数组
        LeetCode696 solution = new LeetCode696();
        Scanner scanner = new Scanner(System.in);
        String m;
        System.out.print("string m: ");
        m = scanner.nextLine();
        //关键是要连续的
        solution.countBinarySubstrings(m);
        scanner.close();
    }
    public int countBinarySubstrings(String s) {
        int ptr = 0, n = s.length(), last = 0, ans = 0;
        while (ptr < n) {
            char c = s.charAt(ptr);
            int count = 0;
            while (ptr < n && s.charAt(ptr) == c) {
                ++ptr;
                ++count;
            }
            ans += Math.min(count, last);
            last = count;
        }
        return ans;
    }
}

/*给定一个字符串 s，计算具有相同数量 0 和 1 的非空（连续）子字符串的数量，并且这些子字符串中的所有 0 和所有 1 都是连续的。

重复出现的子串要计算它们出现的次数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-binary-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// string: 00110011
// 6