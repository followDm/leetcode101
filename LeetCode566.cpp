#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c) {
            return nums;
        }

        vector<vector<int>> ans(r, vector<int>(c));
        for (int x = 0; x < m * n; ++x) {
            ans[x / c][x % c] = nums[x / n][x % n];
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
    cout << "new row and new columns: ";
    cin >> t;
    cin >> n;
    Solution sol;
    grid = sol.matrixReshape(grid, t, n);
    n = grid.size();
    rows = rows * columns / n;
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
// number of rows: 2
// number of columns: 2
// 1 2 3 4
// new row and new columns: 1 4
// [[1,2,3,4]]