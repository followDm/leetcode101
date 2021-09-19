#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
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
    
    Solution sol;
    cout << sol.maxSubArray(nums);
    
    return 0;
}
// number of nums: 9
// -2 1 -3 4 -1 2 1 -5 4
// 6