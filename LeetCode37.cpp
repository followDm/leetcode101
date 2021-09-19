#include <vector>
#include<bitset>
#include<iostream>
using namespace std;

class Solution {
private:
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<vector<bitset<9>>> cells;    
public:
    bitset<9> getPossibleStatus(int x, int y){
        return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
    }

    vector<int> getNext(vector<vector<char>>& board){
        vector<int> ret;
        int minCnt = 10;
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                if (board[i][j] != '.') continue;
                auto cur = getPossibleStatus(i, j);
                if (cur.count() >= minCnt) continue;
                ret = { i, j };
                minCnt = cur.count();
            }
        }
        return ret;
    }

    void fillNum(int x, int y, int n, bool fillFlag){
        rows[x][n] = (fillFlag) ? 1 : 0;
        cols[y][n] = (fillFlag) ? 1 : 0;
        cells[x/3][y/3][n] = (fillFlag) ? 1: 0;
    }
    bool dfs(vector<vector<char>>& board, int cnt){
        if (cnt == 0) return true;

        auto next = getNext(board);
        auto bits = getPossibleStatus(next[0], next[1]);
        for (int n = 0; n < bits.size(); n++){
            if (!bits.test(n)) continue;
            fillNum(next[0], next[1], n, true);
            board[next[0]][next[1]] = n + '1';
            if (dfs(board, cnt - 1)) return true;
            board[next[0]][next[1]] = '.';
            fillNum(next[0], next[1], n, false);
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        rows = vector<bitset<9>>(9, bitset<9>());
        cols = vector<bitset<9>>(9, bitset<9>());
        cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));

        int cnt = 0;
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                cnt += (board[i][j] == '.');
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '1';
                rows[i] |= (1 << n);
                cols[j] |= (1 << n);
                cells[i / 3][j / 3] |= (1 << n);
            }
        }
        dfs(board, cnt);
    }
};

int main(){
    vector<vector<char>> grid;
    vector<char> child;
    int rows = 0, columns = 0, n = 0;
    char t = 0;
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
    sol.solveSudoku(grid);
    n = grid.size();
    
    for (int i = 0; i < n; i++){
        cout << endl;
        for (int k = 0; k < rows - 1; k++){
            cout << grid.at(i).at(k) << " ";
        }
        cout << grid.at(i).at(rows - 1);
    }
    
    return 0;
}
/**
number of rows: 9
number of columns: 9
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9

*/