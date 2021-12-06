#include<vector>
#include<math.h>
#include<iostream>
using namespace std;
class Solution {
public:
    int minSteps1(int n) {
        vector<int> f(n + 1);
        for (int i = 2; i <= n; ++i) {
            f[i] = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                if (i % j == 0) {
                    f[i] = min(f[i], f[j] + i / j);
                    f[i] = min(f[i], f[i / j] + j);
                }
            }
        }
        return f[n];
    }
    int minSteps2(int n) {
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

    enum choose {RE, GA};
    int minSteps(int n, choose c) {
        switch (c){
            case GA:
                return minSteps1(n);
                break;
            case RE:
                return minSteps2(n);
                break;
            default:
                return -1;
                break;
        }
    }
};

int main(){
    int num;
    cout << "num: ";
    cin >> num;
    
    Solution sol;
    cout << boolalpha << sol.minSteps(num, sol.GA);
    return 0;
}
/*最初记事本上只有一个字符 'A' 。你每次可以对这个记事本进行两种操作：

Copy All（复制全部）：复制这个记事本中的所有字符（不允许仅复制部分字符）。
Paste（粘贴）：粘贴 上一次 复制的字符。
给你一个数字 n ，你需要使用最少的操作次数，在记事本上输出 恰好 n 个 'A' 。返回能够打印出 n 个 'A' 的最少操作次数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/2-keys-keyboard
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// num: 3
// 3