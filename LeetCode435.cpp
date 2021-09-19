#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        
        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
            return u[1] < v[1];
        });

        int n = intervals.size();
        int right = intervals[0][1];
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] >= right) {
                ++ans;
                right = intervals[i][1];
            }
        }
        return n - ans;
    }
};
int main(){
    vector<int> child;
    vector<vector<int>> intervals;
    int n = 0, t = 0;
    cout << "number of intervals: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 2; j++){
            cin >> t;
            child.push_back(t);
        }
        intervals.push_back(child);
        child.clear();
    }
    Solution sol;
    cout << sol.eraseOverlapIntervals(intervals);
    return 0;
}
// number of intervals: 3
// 1 2
// 2 4
// 1 3
// 1