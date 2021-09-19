#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
private:
    vector<pair<int, int>> freq;
    vector<vector<int>> ans;
    vector<int> sequence;

public:
    void dfs(int pos, int rest) {
        if (rest == 0) {
            ans.push_back(sequence);
            return;
        }
        if (pos == freq.size() || rest < freq[pos].first) {
            return;
        }

        dfs(pos + 1, rest);

        int most = min(rest / freq[pos].first, freq[pos].second);
        for (int i = 1; i <= most; ++i) {
            sequence.push_back(freq[pos].first);
            dfs(pos + 1, rest - i * freq[pos].first);
        }
        for (int i = 1; i <= most; ++i) {
            sequence.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (int num: candidates) {
            if (freq.empty() || num != freq.back().first) {
                freq.emplace_back(num, 1);
            } else {
                ++freq.back().second;
            }
        }
        dfs(0, target);
        return ans;
    }
};

int main(){
    vector<vector<int>> grid;
    vector<int> candidates;
    int rows = 0, t = 0, n = 0, target;
    cout << "number of nums: ";
    cin >> rows;
    for (int i = 1; i <= rows; i++){
        cin >> t;
        candidates.push_back(t);
    }
    cout << "target: ";
    cin >> target;
    Solution sol;
    grid = sol.combinationSum2(candidates, target);
    n = grid.size();
    cout << "[";
    for (int i = 0; i < n; i++){
        cout << "[";
        for (int k = 0; k < grid[i].size() - 1; k++){
            cout << grid.at(i).at(k) << ",";
        }
        cout << grid.at(i).at(grid[i].size() - 1) << "]";
    }
    cout << "]";
    return 0;
}
// number of nums: 5
// 2 5 2 1 2
// target: 5
// [[5][1,2,2]]