#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int minDistance(string s1, string s2) {
        vector<int> dp (s2.size() + 1, s2.size() + 1);
        for (int i = 0; i <= s1.length(); i++) {
            vector<int> temp(s2.size() + 1, s2.size() + 1);
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 || j == 0)
                    temp[j] = i + j;
                else if (s1.at(i - 1) == s2.at(j - 1))
                    temp[j] = dp[j - 1];
                else
                    temp[j] = 1 + min(dp[j], temp[j - 1]);
            }
            dp=temp;
        }
        return dp[s2.length()];
    }
};

int main(){
    string s1, s2;
    cout << "s1: ";
    cin >> s1;
    cout << "s2: ";
    cin >> s2;
    Solution sol;
    cout << boolalpha << sol.minDistance(s1, s2);
    return 0;
}