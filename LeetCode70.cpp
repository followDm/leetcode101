#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q; 
            q = r; 
            r = p + q;
        }
        return r;
    }
};


int main(){
    int n;
    cout << "n: ";
    cin >> n;
    
    Solution sol;
    cout << boolalpha << sol.climbStairs(n);
    return 0;
}
// n: 3
// 3