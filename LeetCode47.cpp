#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    vector<int> vis;

public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm) {
        if (idx == nums.size()) {
            ans.emplace_back(perm);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, ans, idx + 1, perm);
            vis[i] = 0;
            perm.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, 0, perm);
        return ans;
    }
};

int main(){
    vector<vector<int>> grid;
    vector<int> child;
    int rows = 0, t = 0, n = 0;
    cout << "number of nums: ";
    cin >> rows;
    for (int i = 1; i <= rows; i++){
        cin >> t;
        child.push_back(t);
    }
    Solution sol;
    grid = sol.permuteUnique(child);
    n = grid.size();
    cout << "[";
    for (int i = 0; i < n; i++){
        cout << "[";
        for (int k = 0; k < rows - 1; k++){
            cout << grid.at(i).at(k) << ",";
        }
        cout << grid.at(i).at(rows - 1) << "]";
    }
    cout << "]";
    return 0;
}
// number of nums: 3
// 1 2 1
// [[1,1,2][1,2,1][2,1,1]]