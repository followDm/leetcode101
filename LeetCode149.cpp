#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<cstdlib>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    int maxPoints1(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) {
            return n;
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (ret >= n - i || ret > n / 2) {
                break;
            }
            unordered_map<int, int> mp;
            for (int j = i + 1; j < n; j++) {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                if (x == 0) {
                    y = 1;
                } else if (y == 0) {
                    x = 1;
                } else {
                    if (y < 0) {
                        x = -x;
                        y = -y;
                    }
                    int gcdXY = gcd(abs(x), abs(y));
                    x /= gcdXY, y /= gcdXY;
                }
                mp[y + x * 20001]++;
            }
            int maxn = 0;
            for (auto& [_, num] : mp) {
                maxn = max(maxn, num + 1);
            }
            ret = max(ret, maxn);
        }
        return ret;
    }
    int maxPoints2(vector<vector<int>>& points) {
        unordered_map<double, int> hash;
        int max_count = 0, same = 1, same_y = 1;
        for (int i = 0; i < points.size(); i++) {
            same = 1, same_y = 1;
            for (int j = i + 1; j < points.size(); j++) {
                if(points[i][1] ==  points[j][1]) {
                    ++ same_y;
                    if(points[i][0] ==  points[j][0]) {
                        ++ same;
                    }
                } else {
                    double dx = points[i][0] - points[j][0],
                    dy = points[i][1] - points[j][1];
                    ++ hash[dx / dy];
                }
            }
            max_count = max(max_count, same_y);
            for (auto item : hash) {
                max_count = max(max_count, same + item.second);
            }
            hash.clear();
        }
        return max_count;        
    }
    enum choose {GA, RE};
    auto maxPoints(vector<vector<int>>& points, choose c) {
        switch (c){
        case GA:
            return maxPoints1(points);
            break;
        case RE:
            return maxPoints2(points);
            break;
        default:
            return 0;
            break;
        }
    }
};

int main(){
    vector<vector<int>> grid;
    vector<int> child;
    int rows = 0, t = 0;
    cout << "number of points: ";
    cin >> rows;
    srand(rows);
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= 2; j++){
            t = rand() % 10 + 1;
            child.push_back(t);
        }
        grid.push_back(child);
        child.clear();
    }
    Solution sol;
    cout << sol.maxPoints(grid, sol.RE);
    return 0;
}
/*给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点。求最多有多少个点在同一条直线上。*/
// 哈希表
// number of points: 3
// 1 1
// 2 2
// 3 0
// 2