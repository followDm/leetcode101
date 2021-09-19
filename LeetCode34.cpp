#include <vector>
#include<iostream>
using namespace std;

class Solution { 
public:
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return vector<int>{leftIdx, rightIdx};
        } 
        return vector<int>{-1, -1};
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
    nums = sol.searchRange(nums, target);
    n = nums.size();
    cout << "[";
    for (int i = 0; i < n - 1; i++){
        cout << nums.at(i) << ",";
    }
    cout << nums.at(n - 1) << "]";
    return 0;
}

// 输入：nums = [5,7,7,8,8,10], target = 8
// 输出：[3,4]