#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> getZerosOnes(string& str) {
        vector<int> zerosOnes(2);
        int length = str.length();
        for (int i = 0; i < length; i++) {
            zerosOnes[str[i] - '0']++;
        }
        return zerosOnes;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int length = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        int i = 0, j, k;
        int zeros, ones;
        for (i = 0; i < length; i++) {
            vector<int>&& zerosOnes = getZerosOnes(strs[i]);
            zeros = zerosOnes[0], ones = zerosOnes[1];
            for (j = m; j >= zeros; j--) {
                for (k = n; k >= ones; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    vector<string> strings;
    int n = 0, m = 0;
    string t;
    cout << "number of strings: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        strings.push_back(t);
    }
    
    cout << "m: ";
    cin >> m;
    cout << "n: ";
    cin >> n;
    Solution sol;
    cout << sol.findMaxForm(strings, m, n);
    return 0;
}