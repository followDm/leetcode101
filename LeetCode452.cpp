#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[1] < v[1];
        });
        int pos = points[0][1];
        int ans = 1;
        for (const vector<int>& balloon: points) {
            if (balloon[0] > pos) {
                pos = balloon[1];
                ++ans;
            }
        }
        return ans;
    }
};
int main(){
    vector<int> child;
    vector<vector<int>> points;
    int n = 0, t = 0;
    cout << "number of ballons: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 2; j++){
            cin >> t;
            child.push_back(t);
        }
        points.push_back(child);
        child.clear();
    }
    Solution sol;
    cout << sol.findMinArrowShots(points);
    return 0;
}
/**
 * 输入：points = [[1,2],[3,4],[5,6],[7,8]]
 * 输出：4
 */