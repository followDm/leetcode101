#include <vector>
#include<iostream>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>> matrix, int target) {
        // start our "pointer" in the bottom-left
        int row = matrix.size() - 1;
        int col = 0;

        while (row >= 0 && col < matrix[0].size()) {
            if (matrix[row][col] > target) {
                row--;
            } else if (matrix[row][col] < target) {
                col++;
            } else { // found it
                return true;
            }
        }

        return false;
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
    cout << "target: ";
    cin >> n;
    Solution sol;
    cout << boolalpha << sol.searchMatrix(grid, n);
    return 0;
}
// number of rows: 2
// number of columns: 5
// 1 4 7 11 15
// 2 5 7 12 19
// target: 5
// true