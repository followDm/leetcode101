#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;

class Solution {
public:
    bool wordBreak1(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set <string> ();
        for (auto word: wordDict) {
            wordDictSet.insert(word);
        }

        auto dp = vector <bool> (s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }

    bool wordBreak2(string s, vector<string>& wordDict) {
        int n = s.length();
        vector <bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (const string & word: wordDict) {
                int len = word.length();
                if (i >= len && s.substr(i - len, len) == word) {
                    dp[i] = dp[i] || dp[i -  len];
                }
            }
        }

        return dp[n];
    }

    enum choose {GA, RE};
    bool wordBreak(string s, vector<string>& wordDict, choose c) {
        switch (c){
        case GA:
            return wordBreak1(s, wordDict);
            break;
        case RE:
            return wordBreak2(s, wordDict);
            break;
        default:
            break;
        }
    }
};

int main(){
    vector<string> wordDict;
    string s;
    int n;
    string t;
    cout << "string: ";
    cin >> s;
    cout << "size of wordDict: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        wordDict.push_back(t);
    }
    Solution sol;
    
    cout << boolalpha << sol.wordBreak(s, wordDict, sol.RE);
    return 0;
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