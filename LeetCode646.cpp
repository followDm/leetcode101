#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public: 
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
        });
        int N = pairs.size();
        vector<int> dp(N, 1);

        for (int j = 1; j < N; ++j) {
            for (int i = 0; i < j; ++i) {
                if (pairs[i][1] < pairs[j][0])
                    dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        int ans = 0;
        for (int x: dp) if (x > ans) ans = x;
        return ans;
    }
};

int main(){
    vector<vector<int>> nums;
    vector<int> child;
    int t = 0, n = 0;
    cout << "number of nums: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 2; j++){
            cin >> t;
            child.push_back(t);
        }
        nums.push_back(child);
        child.clear();
    }
    Solution sol;
    cout << sol.findLongestChain(nums);
    return 0;
}
// number of nums: 3
// 1 2
// 2 3
// 3 4
// 2