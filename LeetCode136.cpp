#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto e: nums) ret ^= e;
        return ret;
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
    cout << sol.singleNumber(nums);
    return 0;
}
// number of nums: 3
// 1 2 2
// 1