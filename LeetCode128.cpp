#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;           
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
    cout << sol.longestConsecutive(nums);
    return 0;
}