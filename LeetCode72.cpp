#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    enum choose {GA, RE};
    int minDistance1(string word1, string word2) {
        int n = word1.length(), m = word2.length();

        if (n * m == 0) 
            return n + m;

        int D[n + 1][m + 1];
        int i, j, left, down, left_down;
        for (i = 0; i < n + 1; i++) {
            D[i][0] = i;
        }
        for (j = 0; j < m + 1; j++) {
            D[0][j] = j;
        }
        for (i = 1; i < n + 1; i++) {
            for (j = 1; j < m + 1; j++) {
                left = D[i - 1][j] + 1;
                down = D[i][j - 1] + 1;
                left_down = D[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1])
                    left_down += 1;
                D[i][j] = min(left, min(down, left_down));
            }
        }
        return D[n][m];
    }

    int minDistance2(string word1, string word2) {
        int m = word1.length(), n = word2.length();

        if (n * m == 0) 
            return n + m;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) {
                    dp[i][j] = j;
                } else if (j == 0) {
                    dp[i][j] = i;
                } else {
                    dp[i][j] = min(
                        dp[i-1][j-1] + ((word1[i-1] == word2[i-1]) ? 0 : 1),
                        min(dp[i-1][j] + 1, dp[i][j-1] + 1)
                    );
                }
            }
        }
        return dp[m][n];
    }

    int minDistance(string word1, string word2, choose c) {
        switch (c){
            case GA:
                return minDistance1(word1, word2);
                break;
            case RE:
                return minDistance2(word1, word2);
                break;
            default:
                return -1;
                break;
        }
    }
};

int main(){
    string text1, text2;
    cout << "text1: ";
    cin >> text1;
    cout << "text2: ";
    cin >> text2;
    
    Solution sol;
    cout << boolalpha << sol.minDistance(text1, text2, sol.RE);
    return 0;
}
/*给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/edit-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// text1: hello
// text2: world
// 4