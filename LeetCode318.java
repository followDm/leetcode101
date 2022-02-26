import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class LeetCode318 {
    public static void main(String[] args) {
        //一维整数数组
        LeetCode318 solution = new LeetCode318();
        Scanner scanner = new Scanner(System.in);
        
        int rows = 0;
        System.out.print("number of strs: ");
        rows = scanner.nextInt();
        String [] words = new String[rows];
        for (int i = 1; i <= rows; i++){
            words[i-1] = scanner.next();
        }
        //不含相同字母的字符串的长度乘积最大值
        //英文字母用二的正整数幂表示，然后位运算
        solution.maxProduct(words);
        scanner.close();
    }
    public int bitNumber(char ch){
        return (int)ch - (int)'a';
    }
    
    public int maxProduct(String[] words) {
        Map<Integer, Integer> hashmap = new HashMap();
    
        int bitmask = 0;
        for (String word : words) {
            bitmask = 0;
            for (char ch : word.toCharArray()) {
                // add bit number bitNumber in bitmask
                bitmask |= 1 << bitNumber(ch);
            }
            // there could be different words with the same bitmask
            // ex. ab and aabb
            hashmap.put(bitmask, Math.max(hashmap.getOrDefault(bitmask, 0), word.length()));
        }
    
        int maxProd = 0;
        for (int x : hashmap.keySet())
            for (int y : hashmap.keySet())
                if ((x & y) == 0) 
                    maxProd = Math.max(maxProd, hashmap.get(x) * hashmap.get(y));
    
        return maxProd;
    }
}

/*给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-of-word-lengths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// 一个长度26的二进制
// size of words: 7
// a ab abc d cd bcd abcd
// 4