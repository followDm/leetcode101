#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), l = 0, ans = 0;
        if(n < 3)
            return 0;
        for(int i = 2; i < n; i++)  
            nums[i] - nums[i-1] == nums[i-1] - nums[i-2] ? ans += ++l : l = 0;
        return ans;
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
// number of nums: 5
// 1 2 3 4 5
// 6