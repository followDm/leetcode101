import java.util.Scanner;
import java.util.Set;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class LeetCode139{
    public static void main(String[] args) {
        LeetCode139 solution = new LeetCode139();
        Scanner scanner = new Scanner(System.in);
        
        int rows = 0;
        System.out.print("s: ");
        String s = scanner.next();
        System.out.print("number of words:");
        rows = scanner.nextInt();
        List<String> wordDict = new ArrayList<>();
        for (int i = 1; i <= rows; i++){
            wordDict.add(scanner.next());
        }
        solution.wordBreak(s, wordDict);
        scanner.close();
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> wordDictSet = new HashSet(wordDict);
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordDictSet.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
}
/*给你一个字符串 s 和一个字符串列表 wordDict 作为字典，判定 s 是否可以由空格拆分为一个或多个在字典中出现的单词。

说明：拆分时可以重复使用字典中的单词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// string: snow
// size of wordDict: 1
// snowy
// false