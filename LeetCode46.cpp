#include <vector>
#include<iostream>
using namespace std;

void backtracking(vector<int>& nums, int level, vector<vector<int>>& ans){
    if(level == nums.size() - 1){
        ans.push_back(nums);
        return ;
    }
    for (int i = level; i < nums.size(); i++){
        swap(nums[i], nums[level]);
        backtracking(nums, level + 1, ans);
        swap(nums[i], nums[level]);
    }
    
}

vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    backtracking(nums, 0, ans);
    return ans;
}

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
    grid = permute(child);
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
// 1 2 3
// [[1,2,3][1,3,2][2,1,3][2,3,1][3,2,1][3,1,2]]