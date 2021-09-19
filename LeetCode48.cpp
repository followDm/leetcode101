#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 1) / 2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};
int main(){
    vector<vector<int>> grid;
    vector<int> child;
    int rows = 0, columns = 0, t = 0, n = 0;
    cout << "number of rows: ";
    cin >> rows;
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= rows; j++){
            cin >> t;
            child.push_back(t);
        }
        grid.push_back(child);
        child.clear();
    }
    Solution sol;
    sol.rotate(grid);
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
// number of rows: 3
// 1 2 3 
// 4 5 6
// 7 8 9
// [[7,4,1][8,5,2][9,6,3]]