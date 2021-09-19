#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int k) {
        if (board[i][j] != s[k]) {
            return false;
        } else if (k == s.length() - 1) {
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (const auto& dir: directions) {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj]) {
                    bool flag = check(board, visited, newi, newj, s, k + 1);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    vector<vector<char>> board;
    vector<char> child;
    string s;
    int rows = 0, columns = 0;
    char t;
    cout << "number of rows: ";
    cin >> rows;
    cout << "number of columns: ";
    cin >> columns;
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= columns; j++){
            cin >> t;
            child.push_back(t);
        }
        board.push_back(child);
        child.clear();
    }
    cout << "s: ";
    cin >> s;
    Solution sol;
    cout << boolalpha << sol.exist(board, s);
    return 0;
}
// number of rows: 3
// number of columns: 4
// a b c e
// s f c s
// a d e e
// s: abcced
// true