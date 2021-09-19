#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price: prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
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
    cout << sol.maxProfit(days);
    return 0;
}
// number of days: 6
// 7 1 5 3 6 4
// 5