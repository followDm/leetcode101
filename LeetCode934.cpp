#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};

    //主函数
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        queue<pair<int, int>> points;
        //dfs寻找第一个岛屿，并把1全部赋值为2
        bool flipped = false;
        for (int i = 0; i < m; ++i) {
            if (flipped) 
                break;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(points, grid, m, n, i, j);
                    flipped = true;
                    break;
                }
            }
        }
        // bfs寻找第二个岛屿，并把过程中经过的0赋值为2
        int x, y;
        int level = 0;
        while (!points.empty()){
            ++level;
            int n_points = points.size();
            while (n_points--) {
                auto [r, c] = points.front();
                points.pop();
                for (int k = 0; k < 4; ++k) {
                    x = r + direction[k], y = c + direction[k+1];
                    if (x >= 0 && y >= 0 && x < m && y < n) {
                        if (grid[x][y] == 2) {
                            continue;
                        }
                        if (grid[x][y] == 1) {
                            return level;
                        }
                        points.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return 0;        
    }

    void dfs(queue<pair<int, int>>& points, vector<vector<int>>& grid, int m, int n, int i, int j) {
        if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 2) {
            return;
        }
        if (grid[i][j] == 0) {
            points.push({i, j});
            return;
        }
        grid[i][j] = 2;
        dfs(points, grid, m, n, i - 1, j);
        dfs(points, grid, m, n, i + 1, j);
        dfs(points, grid, m, n, i, j - 1);
        dfs(points, grid, m, n, i, j + 1);
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
    cout << sol.shortestBridge(grid);
    return 0;
}
/*
在给定的二维二进制数组 A 中，存在两座岛。（岛是由四面相连的 1 形成的一个最大组。）

现在，我们可以将 0 变为 1，以使两座岛连接起来，变成一座岛。

返回必须翻转的 0 的最小数目。（可以保证答案至少是 1 。）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-bridge
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// 广度优先查找
// number of rows: 5
// number of columns: 5
// 1 1 1 1 1
// 1 0 0 0 1
// 1 0 1 0 1
// 1 0 0 0 1
// 1 1 1 1 1
// 1