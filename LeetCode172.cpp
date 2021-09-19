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
// n: 12
// 2