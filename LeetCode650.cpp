#include<vector>
#include<math.h>
#include<iostream>
using namespace std;
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1);
        int h = sqrt(n);
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;
            for (int j = 2; j <= h; ++j) {
                if (i % j == 0){
                    dp[i] = dp[j] + dp[i / j];
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main(){
    int num;
    cout << "num: ";
    cin >> num;
    
    Solution sol;
    cout << boolalpha << sol.minSteps(num);
    return 0;
}
// num: 3
// 3