#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
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
// number of days: 5
// 1 2 3 0 2
// 3