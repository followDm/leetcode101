#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        int m = primes.size();
        vector<int> pointers(m, 1);
        for (int i = 2; i <= n; i++) {
            vector<int> nums(m);
            int minNum = INT_MAX;
            for (int j = 0; j < m; j++) {
                nums[j] = dp[pointers[j]] * primes[j];
                minNum = min(minNum, nums[j]);
            }
            dp[i] = minNum;
            for (int j = 0; j < m; j++) {
                if (minNum == nums[j]) {
                    pointers[j]++;
                }
            }
        }
        return dp[n];
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
    cout << sol.nthSuperUglyNumber(target, nums);
    n = nums.size();
    return 0;
}
// number of nums: 5
// 2 7 13 17 19
// target: 12
// 28