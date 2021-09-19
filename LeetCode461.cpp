#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int s = x ^ y, ret = 0;
        while (s) {
            ret += s & 1;
            s >>= 1;
        }
        return ret;
    }
};

int main(){
    int n = 0, t = 0;
    cout << "n: ";
    cin >> n;
    cout << "t: ";
    cin >> t;
    Solution sol;
    cout << sol.hammingDistance( n, t);
    return 0;
}
// n: 1
// t: 4
// 2