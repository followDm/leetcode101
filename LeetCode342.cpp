#include<iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
    }
};

int main(){
    int n = 0;
    cout << "n: ";
    cin >> n;
    
    Solution sol;
    cout << boolalpha << sol.isPowerOfFour(n);
    return 0;
}
// n: 16
// true