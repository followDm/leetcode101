#include <vector>
#include<iostream>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;

    vector<string> stk;

    void dfs(const string& curr) {
        while (vec.count(curr) && vec[curr].size() > 0) {
            string tmp = vec[curr].top();
            vec[curr].pop();
            dfs(move(tmp));
        }
        stk.emplace_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& it : tickets) {
            vec[it[0]].emplace(it[1]);
        }
        dfs("JFK");

        reverse(stk.begin(), stk.end());
        return stk;
    }
};

int main(){
    vector<vector<string>> tickets;
    vector<string> child;
    int rows = 0, columns = 0, n = 0;
    string t;
    cout << "number of tickets: ";
    cin >> rows;
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= 2; j++){
            cin >> t;
            child.push_back(t);
        }
        tickets.push_back(child);
        child.clear();
    }
    Solution sol;
    child = sol.findItinerary(tickets);
    n = child.size();
    cout << "[";
    for (int i = 0; i < n - 1; i++){
        cout << child.at(i) << ",";
    }
    cout << child.at(n - 1) << "]";

    return 0;
}
// number of tickets: 4
// MUC LHR
// JFK MUC
// SFO MUC
// LHR SFO
// [JFK,MUC,LHR,SFO,MUC]