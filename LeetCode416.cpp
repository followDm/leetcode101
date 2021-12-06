#include <iostream>
#include <vector>
#include<numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) {
            return false;
        }
        int target = sum / 2, n = nums.size();
        
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = target; j >= nums[i-1]; --j) {
                dp[j] = dp[j] || dp[j-nums[i-1]];
            }
        }
        return dp[target];
    }
};

int main(){
    vector<int> nums;
    int n = 0, t = 0;
    cout << "number of nums: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        nums.push_back(t);
    }
    Solution sol;
    cout << boolalpha << sol.canPartition(nums);
    return 0;
}
/*给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。*/
// 背包问题
// number of nums: 4
// 1 5 5 11
// true