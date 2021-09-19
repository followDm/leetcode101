#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int> nums) {
        int missing = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            missing ^= i ^ nums[i];
        }
        return missing;
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
    cout << sol.missingNumber(nums);
    return 0;
}
// number of nums: 3
// 1 2 3
// 0