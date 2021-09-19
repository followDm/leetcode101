#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {   
        int ans = 0;
        int n = prices.size();
        for (int i = 1; i < n; ++i) {
            ans += max(0, prices[i] - prices[i - 1]);
        }
        return ans;
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
/**
 * 输入: prices = [7,1,5,3,6,4]
 * 输出: 7
 */