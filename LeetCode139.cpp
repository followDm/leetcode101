#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
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
    cout << boolalpha << sol.wordBreak(s, wordDict);
    return 0;
}
// string: snow
// size of wordDict: 1
// snowy
// false