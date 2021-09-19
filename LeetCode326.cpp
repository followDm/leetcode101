#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};

int main(){
    int n;
    cout << "n: ";
    cin >> n;
    
    Solution sol;
    cout << boolalpha << sol.isPowerOfThree(n);
    return 0;
}
// n: 27
// true