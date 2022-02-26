import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class LeetCode205 {
    public static void main(String[] args) {
        //两个字符串
        LeetCode205 solution = new LeetCode205();
        Scanner scanner = new Scanner(System.in);
        
        String n, m;
        System.out.print("string m: ");
        m = scanner.nextLine();
        System.out.print("string n: ");
        n = scanner.nextLine();
        //字符串同构
        //复杂点的版本https://leetcode-cn.com/problems/word-pattern/solution/dan-ci-gui-lu-by-leetcode-solution-6vqv/
        solution.isIsomorphic(m, n);
        scanner.close();
    }
    public boolean isIsomorphic(String s, String t) {
        Map<Character, Character> s2t = new HashMap<Character, Character>();
        Map<Character, Character> t2s = new HashMap<Character, Character>();
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            char x = s.charAt(i), y = t.charAt(i);
            if ((s2t.containsKey(x) && s2t.get(x) != y) || (t2s.containsKey(y) && t2s.get(y) != x)) {
                return false;
            }
            s2t.put(x, y);
            t2s.put(y, x);
        }
        return true;
    }
}

/*给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。

每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/isomorphic-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// ABB ABACD 等等
// string1: hello
// string2: world
// false
//不存在键值对就添加，存在键值对但是不对应就返回false