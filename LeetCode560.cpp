#include<vector>
#include<unordered_map>
#include<iostream>
#include<cstdlib>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto& x:nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};

int main(){
    vector<int> nums;
    int n = 0, t = 0, target;
    cout << "number of nums: ";
    cin >> n;
    srand(n);
    for (int i = 1; i <= n; i++){
        t = rand() % 10 + 1;
        nums.push_back(t);
    }
    
    target = n * (rand() % 10 + 1);
    Solution sol;
    cout <<sol.subarraySum(nums, target);
    return 0;
}
/*给你一个整数数组 nums 和一个整数 k ，请你统计并返回该数组中和为 k 的连续子数组的个数。*/
// 前缀和
// number of nums: 3
// 2 2 2
// target: 2
// 3