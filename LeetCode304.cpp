#include<vector>
#include<iostream>
#include<cstdlib>
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
        // 为了验证
        int rows = sums.size(), columns = sums[0].size();
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                cout << sums[i][j] << " ";
            }
            cout << endl;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        cout << row2 + 1 << col2 + 1<< row1<< col2 + 1<< row2 + 1<< col1<< row1<< col1 << endl;
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
    srand(rows + columns);
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= columns; j++){
            t = rand() % 10 + 1;
            child.push_back(t);
        }
        grid.push_back(child);
        child.clear();
    }
    NumMatrix sol = NumMatrix(grid);
    cout << sol.sumRegion(rand() % rows, rand() % columns, rand() % rows, rand() % columns) << endl;
    return 0;
}
/*给定一个二维矩阵 matrix，以下类型的多个请求：

计算其子矩形范围内元素的总和，该子矩阵的 左上角 为 (row1, col1) ，右下角 为 (row2, col2) 。
实现 NumMatrix 类：

NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
int sumRegion(int row1, int col1, int row2, int col2) 返回 左上角 (row1, col1) 、右下角 (row2, col2) 所描述的子矩阵的元素 总和 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-2d-immutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
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