#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isMatch1(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }

    bool isMatch2(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i < n + 1; i++){
            if (p[i-1] == '*') {
                dp[0][i] = dp[0][i-2];
            }
        }
        for (int i = 1; i < m + 1; i++){
            for (int j = 1; j < n + 1; j++){
                if(p[i-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] != '*') {
                    dp[i][j] = dp[i-1][j-1] && p[j-1] == s[i-1];
                } else if (p[j-2] != s[i-1] && p[j-2] != '.') {
                    dp[i][j] = dp[i][j-2];
                } else {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i][j-2];
                }
            }
            
        }
        return dp[m][n];
    }

    enum choose {GA, RE};

    bool isMatch(string s, string p, choose c) {
        switch (c){
            case GA:
                return isMatch1(s, p);
                break;
            case RE:
                return isMatch2(s, p);
                break;
            default:
                return false;
                break;
        }
    }
};

int main(){
    string s, pattern;
    cout << "string: ";
    cin >> s;
    cout << "pattern: ";
    cin >> pattern;
    Solution sol;
    cout << boolalpha << sol.isMatch(s, pattern, sol.RE);
    return 0;
}
/*???????????????????????s?????????????????????????p?????????????????????????????? '.'???????'*'?????????????????????????????

'.' ????????????????????????
'*' ?????????????????????????????????????????????
????????????????????????????????????????????????s?????????????????????????????????

??????????????????LeetCode???
?????????https://leetcode-cn.com/problems/regular-expression-matching
??????????????????????????????????????????????????????????????????????????????????????????????????????*/
// ????????????
// string: aab
// pattern: a*b
// true