#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int zeroCount = 0;
        long currentMultiple = 5;
        while (n > 0) {
            n /= 5;
            zeroCount += n;
        }
        return zeroCount;
    }
};

int main(){
    int n;
    cout << "n: ";
    cin >> n;
    
    Solution sol;
    cout << sol.trailingZeroes(n);
    return 0;
}
/*给定一个整数 n ，返回 n! 结果中尾随零的数量。

提示 n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1*/
// n: 12
// 2