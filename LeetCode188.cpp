#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit1(int k, vector<int>& prices) {
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
    int maxProfit2(int k, vector<int>& prices) {
        int days = prices.size();
        if (days < 2) {
            return 0;
        }
        if (k >= days) {
            return maxProfitUnlimited(prices);
        }
        // buy[i]第i次买入最大收益sell第i次卖出最大收益
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        // 书里少了这一步，相当于初始化
        buy[0] = -prices[0];
        for (int i = 0; i < days; i++){
            for (int j = 1; j <= k; j++){
                buy[j] = max(buy[j], sell[j-1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }

        return sell[k];   
    }

    int maxProfitUnlimited(vector<int> prices) {
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1]) {
                maxProfit += prices[i] - prices[i-1];
            }
        }
        return maxProfit;
    }
    enum choose {GA, RE};

    int maxProfit(int k, vector<int>& prices, choose c) {
        switch (c){
            case GA:
                return maxProfit1(k, prices);
                break;
            case RE:
                return maxProfit2(k, prices);
                break;
            default:
                return -1;
                break;
        }
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
    cout << "GA" << sol.maxProfit(n, prices, sol.GA) << endl;
    cout << "RE" << sol.maxProfit(n, prices, sol.RE);
    return 0;
}
/*给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// number of days: 6
// 3 2 6 5 0 3
// number of k: 2
// 7