#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int maxProfit1(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price: prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
    enum choose {GA, RE};
    int maxProfit2(vector<int>& prices) {
        int sell = 0, buy = INT_MIN;
        for (int i = 0; i < prices.size(); i++){
            buy = max(buy, -prices[i]);
            sell = max(sell, buy + prices[i]);
        }
        return sell;
    }

    int maxProfit(vector<int>& prices, choose c) {
        switch (c){
            case GA:
                return maxProfit1(prices);
                break;
            case RE:
                return maxProfit2(prices);
                break;
            default:
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
/*给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// number of days: 6
// 7 1 5 3 6 4
// 5