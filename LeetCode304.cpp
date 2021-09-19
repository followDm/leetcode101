#include<vector>
#include<iostream>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> sums;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m > 0) {
            int n = matrix[0].size();
            sums.resize(m + 1, vector<int>(n + 1));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    sums[i + 1][j + 1] = sums[i][j + 1] + sums[i + 1][j] - sums[i][j] + matrix[i][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2 + 1][col2 + 1] - sums[row1][col2 + 1] - sums[row2 + 1][col1] + sums[row1][col1];
    }
};

int main(){
    vector<vector<int>> grid, point;
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
    NumMatrix sol = NumMatrix(grid);
    cout << "number of ponits: ";
    cin >> rows;
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= 4; j++){
            cin >> t;
            child.push_back(t);
        }
        point.push_back(child);
        child.clear();
    }
    for (int i = 0; i < rows; i++){
        cout << sol.sumRegion(point[i][0], point[i][1], point[i][2], point[i][3]) << endl;
    }
    
    return 0;
}
// number of rows: 5
// number of columns: 5
// 3 0 1 4 2
// 5 6 3 2 1
// 1 2 0 1 5
// 4 1 0 1 7
// 1 0 3 0 5
// number of ponits: 1
// 2 1 4 3
// 8