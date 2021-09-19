#include<vector>
#include<iostream>
using namespace std;

void backtracking(vector<vector<int>>& ans, vector<int>& comb, int& count, int pos, int n, int k){
    if(count == k){
        ans.push_back(comb);
        return ;
    }
    for (int i = pos; i <= n; i++){
        comb[count++] = i;
        backtracking(ans, comb, count, i + 1, n, k);
        --count;
    }
    
}

vector<vector<int>> combine(int n, int k){
    vector<vector<int>> ans;
    vector<int> comb(k, 0);
    int count = 0;
    backtracking(ans, comb, count, 1, n, k);
    return ans;
}
int main(){
    vector<vector<int>> grid;
    vector<int> child;
    int t = 0, n = 0;
    cout << "number of n: ";
    cin >> n;
    cout << "number of t(t<=n): ";
    cin >> t;
    grid = combine(n, t);
    n = grid.size();
    cout << "[";
    for (int i = 0; i < n; i++){
        cout << "[";
        for (int k = 0; k < t - 1; k++){
            cout << grid.at(i).at(k) << ",";
        }
        cout << grid.at(i).at(t - 1) << "]";
    }
    cout << "]";
    return 0;
}
// number of n: 4
// number of t(t<=n): 2
// [[1,2][1,3][1,4][2,3][2,4][3,4]]