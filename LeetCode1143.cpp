#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        char c1, c2;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            c1 = text1.at(i - 1);
            for (int j = 1; j <= n; j++) {
                c2 = text2.at(j - 1);
                if (c1 == c2) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    string text1, text2;
    cout << "text1: ";
    cin >> text1;
    cout << "text2: ";
    cin >> text2;
    
    Solution sol;
    cout << boolalpha << sol.longestCommonSubsequence(text1, text2);
    return 0;
}
// text1: abcde
// text2: abd
// 3