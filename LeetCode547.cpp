#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int provinces, int i) {
        for (int j = 0; j < provinces; j++) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                visited[j] = 1;
                dfs(isConnected, visited, provinces, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = isConnected.size();
        vector<int> visited(provinces);
        int circles = 0;
        for (int i = 0; i < provinces; i++) {
            if (!visited[i]) {
                dfs(isConnected, visited, provinces, i);
                circles++;
            }
        }
        return circles;
    }
};

int main(){
    vector<vector<int>> friends;
    vector<int> child;
    int rows = 0, t = 0;
    cout << "number of friends: ";
    cin >> rows;
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= rows; j++){
            cin >> t;
            child.push_back(t);
        }
        friends.push_back(child);
        child.clear();
    }
    Solution sol;
    cout << sol.findCircleNum(friends);
    return 0;
}
// number of friends: 3
// 1 1 0
// 1 1 0
// 0 0 1
// 2