#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int rows = grid.size(), columns = grid[0].size();
        auto dp = vector <vector<int>> (rows, vector <int> (columns));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < rows; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < columns; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < columns; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[rows - 1][columns - 1];
    }
    // 对空间压缩
    int minPathSum2(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int rows = grid.size(), columns = grid[0].size();
        vector<int> dp(n,0);
        dp[0][0] = grid[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++){
                if(i == 0 && j == 0){
                    dp[j] = grid[i][j];
                } else if(i == 0) {
                    dp[j] = dp[j-1] + grid[i][j];
                } else if(j == 0) {
                    dp[j] = dp[j] + grid[i][j];
                } else {
                    dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
                }
            }
            
        }
        
        return [columns - 1];
    }
};

int main(){
    vector<vector<int>> grid;
    vector<int> child;
    int rows = 0, columns = 0, t = 0, n = 0;
    cout << "number of rows: ";
    cin >> rows;
    cout << "number of columns: ";
    cin >> columns;
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= columns; j++){
            cin >> t;
            child.push_back(t);
        }
        grid.push_back(child);
        child.clear();
    }
    Solution sol;
    cout << sol.minPathSum(grid);
    return 0;
}
/*
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。*/
// number of rows: 3
// number of columns: 3
// 1 3 1
// 1 5 1
// 4 2 1
// 7