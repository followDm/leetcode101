#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1);
        int minn = (INT_MAX - 1) / 2;
        for (int i = 1; i <= n; i++) {
            minn = (INT_MAX - 1) / 2;
            for (int j = 1; j * j <= i; j++) {
                minn = min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }
        return f[n];
    }
};

int main(){
    int num;
    cout << "num: ";
    cin >> num;
    
    Solution sol;
    cout << boolalpha << sol.numSquares(num);
    return 0;
}
// num: 26
// 2