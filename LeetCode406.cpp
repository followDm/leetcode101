#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
        });
        int n = people.size();
        vector<vector<int>> ans(n);
        for (const vector<int>& person: people) {
            int spaces = person[1] + 1;
            for (int i = 0; i < n; ++i) {
                if (ans[i].empty()) {
                    --spaces;
                    if (!spaces) {
                        ans[i] = person;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> people;
    vector<int> child;
    int n = 0, t = 0;
    cout << "number of people: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 2; j++){
            cin >> t;
            child.push_back(t);
        }
        people.push_back(child);
        child.clear();
    }
    Solution sol;
    people = sol.reconstructQueue(people);
    cout << "[";
    for (int i = 0; i < n - 1; i++){
        cout << "[" << people.at(i).at(0) << "," << people.at(i).at(1) << "]";
    }
    cout << "[" << people.at(n - 1).at(0) << "," << people.at(n - 1).at(1) << "]" << "]";
    return 0;
}
/**
 * 输入：people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
 * 输出：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
 */