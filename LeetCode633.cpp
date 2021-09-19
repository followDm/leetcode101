#include<math.h>
#include<iostream>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0;
        long right = (int)sqrt(c);
        while (left <= right) {
            long sum = left * left + right * right;
            if (sum == c) {
                return true;
            } else if (sum > c) {
                right--;
            } else {
                left++;
            }
        }
        return false;
    }
};

int main(){
    int n = 0, t = 0;
    cout << "number: ";
    cin >> n;
    
    Solution sol;
    cout << boolalpha << sol.judgeSquareSum(n);
    return 0;
}
// 输入：c = 5
// 输出：true
// 解释：1 * 1 + 2 * 2 = 5