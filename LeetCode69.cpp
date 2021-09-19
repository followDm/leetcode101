#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

int main(){
    int num = 0;
    cout << "num: ";
    cin >> num;
    Solution sol;
    cout << sol.mySqrt(num);
    return 0;
}
// num: 17
// 4