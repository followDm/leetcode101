#include <vector>
#include<iostream>
#include<numeric>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), l = 0;
        if(n < 3)
            return 0;
        vector<int> dp(n,0);
        for(int i = 2; i < n; i++)  
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
                dp[i] =dp[i-1] + 1;
        return accumulate(dp.begin(), dp.end(), 0);
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
    cout << sol.numberOfArithmeticSlices(nums);
    return 0;
}
/*
如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列。

例如，[1,3,5,7,9]、[7,7,7,7] 和 [3,-1,-5,-9] 都是等差数列。
给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的 子数组 个数。

子数组 是数组中的一个连续序列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/arithmetic-slices
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// 动态规划
// number of nums: 5
// 1 2 3 4 5
// 6