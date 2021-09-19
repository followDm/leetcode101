#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return {};
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                }else{
                    if (i - 1 >= 0) {
                        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    }
                    if (j - 1 >= 0) {
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                    }
                }
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if(matrix[i][j] != 0){
                    if (i + 1 < m) {
                        dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                    }
                    if (j + 1 < n) {
                        dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
                    }                    
                }

            }
        }
        return dist;
    }
};

int main(){
    vector<vector<int>> matrix;
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
        matrix.push_back(child);
        child.clear();
    }
    Solution sol;
    matrix = sol.updateMatrix(matrix);
    n = matrix.size();
    cout << "[";
    for (int i = 0; i < n; i++){
        cout << "[";
        for (int k = 0; k < matrix[0].size() - 1; k++){
            cout << matrix.at(i).at(k) << ",";
        }
        cout << matrix.at(i).at(matrix[0].size() - 1) << "]";
    }
    cout << "]";
    return 0;
}
// number of rows: 3
// number of columns: 4
// 0 0 0 0
// 0 1 1 0
// 1 1 1 1
// [[0,0,0,0][0,1,1,0][1,2,2,1]]