#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};

int main(){
    vector<int> prices;
    int n = 0, t = 0, pee;
    cout << "number of nums: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        prices.push_back(t);
    }
    
    cout << "pee: ";
    cin >> pee;
    Solution sol;
    cout << sol.maxProfit(prices, pee);
    return 0;
}
// number of nums: 6
// 1 3 2 8 4 9
// pee: 2
// 8