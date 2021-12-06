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
/*两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。

给你两个整数 x 和 y，计算并返回它们之间的汉明距离。*/
// 异或一下就行了
// n: 1
// t: 4
// 2