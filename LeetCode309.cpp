#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxProfit1(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int n = prices.size();
        int f0 = -prices[0];
        int f1 = 0;
        int f2 = 0;
        int newf0, newf1, newf2;
        for (int i = 1; i < n; ++i) {
            newf0 = max(f0, f2 - prices[i]);
            newf1 = f0 + prices[i];
            newf2 = max(f1, f2);
            f0 = newf0;
            f1 = newf1;
            f2 = newf2;
        }
        return max(f1, f2);
    }
    int maxProfit2(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        vector<int> buy(n), sell(n), s1(n), s2(n);
        s1[0] = buy[0] = -prices[0];
        sell[0] = s2[0] = 0;
        for (int i = 1; i < n; i++) {
            buy[i] = s2[i-1] - prices[i];
            s1[i] = max(buy[i-1], s1[i-1]);
            sell[i] = max(buy[i-1], s1[i-1]) + prices[i];
            s2[i] = max(s2[i-1], sell[i-1]);
        }
        return max(sell[n-1], s2[n-1]);
    }
    enum choose {GA, RE};
    int maxProfit(vector<int>& prices, choose c) {
        switch (c){
        case GA:
            return maxProfit1(prices);
            break;
        case RE:
            return maxProfit2(prices);
            break;
        default:
            return -1;
            break;
        }
    }
};

int main(){
    vector<int> days;
    int n = 0, t = 0;
    cout << "number of days: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        days.push_back(t);
    }
    Solution sol;
    cout << sol.maxProfit(days, sol.RE);
    return 0;
}
/*给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// number of days: 5
// 1 2 3 0 2
// 3