import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class LeetCode242 {
    public static void main(String[] args) {
        //两个字符串
        LeetCode242 solution = new LeetCode242();
        Scanner scanner = new Scanner(System.in);
        
        String n, m;
        System.out.print("string m: ");
        m = scanner.nextLine();
        System.out.print("string n: ");
        n = scanner.nextLine();
        
        solution.isAnagram(m, n);
        scanner.close();
    }
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        Map<Character, Integer> table = new HashMap<Character, Integer>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            table.put(ch, table.getOrDefault(ch, 0) + 1);
        }
        for (int i = 0; i < t.length(); i++) {
            char ch = t.charAt(i);
            table.put(ch, table.getOrDefault(ch, 0) - 1);
            if (table.get(ch) < 0) {
                return false;
            }
        }
        return true;
    }
}

/*给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-anagram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// 每个字符出现次数相同
// string1: hello
// string2: wrold
// false