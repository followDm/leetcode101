#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};

    void dfs(const vector<vector<int>>& matrix, vector<vector<bool>>& can_reach, int r, int c){
        if(can_reach[r][c]){
            return ;
        }
        can_reach[r][c] = true;
        int x, y;
        for (int k = 0; k < 4; ++k){
            x = r + direction[k];
            y = c + direction[k + 1];
            if(x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[r][c] <= matrix[x][y]){
                dfs(matrix, can_reach, x, y);
            }
        }
    }

    vector<vector<int>> pacifiaAtlantic(vector<vector<int>>& matrix){
        if(matrix.empty() || matrix[0].empty()){
            return {};
        }
        vector<vector<int>> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<bool>> can_reach_p(m, vector<bool>(n, false));
        vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++){
            dfs(matrix, can_reach_p, i, 0);
            dfs(matrix, can_reach_a, i, n - 1);
        }
        for (int i = 0; i < n; i++){
            dfs(matrix, can_reach_p, 0, i);
            dfs(matrix, can_reach_a, m - 1, i);
        }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(can_reach_p[i][j] && can_reach_a[i][j]){
                    ans.push_back(vector<int>{i, j});
                }
            }
            dfs(matrix, can_reach_p, i, 0);
            dfs(matrix, can_reach_a, i, n - 1);
        }
        return ans;
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
    grid = sol.pacifiaAtlantic(grid);
    n = grid.size();
    cout << "[";
    for (int i = 0; i < n - 1; i++){
        cout << "[" << grid.at(i).at(0) << "," << grid.at(i).at(1) << "]";
    }
    cout << "[" << grid.at(n - 1).at(0) << "," << grid.at(n - 1).at(1) << "]" << "]";
    return 0;
}
// number of rows: 5
// number of columns: 5
// 1 2 2 3 5
// 3 2 3 4 4
// 2 4 5 3 1
// 6 7 1 4 5
// 5 1 1 2 4
// [[0,4][1,3][1,4][2,2][3,0][3,1][4,0]]