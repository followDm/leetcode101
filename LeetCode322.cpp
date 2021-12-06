#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty())
            return -1;
        vector<int> dp(amount + 1, amount + 2);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (const int & coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == amount + 2 ? -1 : dp[amount];
    }
};

int main(){
    vector<int> nums;
    int n = 0, t = 0, target;
    cout << "number of nums: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        nums.push_back(t);
    }
    
    cout << "target: ";
    cin >> target;
    Solution sol;
    cout << sol.coinChange(nums, target);
    return 0;
}
/*给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-change
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// 完全背包
// number of nums: 3
// 1 2 5
// target: 11
// 3