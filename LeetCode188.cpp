#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        k = min(k, n / 2);
        vector<int> buy(k + 1);
        vector<int> sell(k + 1);

        buy[0] = -prices[0];
        sell[0] = 0;
        for (int i = 1; i <= k; ++i) {
            buy[i] = sell[i] = INT_MIN / 2;
        }

        for (int i = 1; i < n; ++i) {
            buy[0] = max(buy[0], sell[0] - prices[i]);
            for (int j = 1; j <= k; ++j) {
                buy[j] = max(buy[j], sell[j] - prices[i]);
                sell[j] = max(sell[j], buy[j - 1] + prices[i]);   
            }
        }

        return *max_element(sell.begin(), sell.end());
    }
};

int main(){
    vector<int> prices;
    int n = 0, t = 0;
    cout << "number of days: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        prices.push_back(t);
    }
    cout << "number of k: ";
    cin >> n;
    Solution sol;
    cout << sol.maxProfit(n, prices);
    return 0;
}
// number of days: 6
// 3 2 6 5 0 3
// number of k: 2
// 7