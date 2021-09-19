#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int num : nums) {
            if (num == candidate)
                ++count;
            else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }
        if(count == 0)
            return nums.size();
        else
            return candidate;
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
    cout << sol.majorityElement(nums);
    return 0;
}
// nums:      [7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 7, 7, 7, 7]
// count:      1  2  1  2  1  0   1  0   1  2  1  0   1  2  3  4
// value:      1  2  1  2  1  0  -1  0  -1 -2 -1  0   1  2  3  4