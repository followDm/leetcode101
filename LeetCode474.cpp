#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> getZerosOnes(string& str) {
        vector<int> zerosOnes(2);
        int length = str.length();
        for (int i = 0; i < length; i++) {
            zerosOnes[str[i] - '0']++;
        }
        return zerosOnes;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int length = strs.size();
        // 两个&什么意思啊
        vector<vector<int>>&& dp(m + 1, vector<int>(n + 1));
        int i = 0, j, k;
        int zeros, ones;
        for (i = 0; i < length; i++) {
            vector<int> zerosOnes = getZerosOnes(strs[i]);
            zeros = zerosOnes[0], ones = zerosOnes[1];
            for (j = m; j >= zeros; j--) {
                for (k = n; k >= ones; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    vector<string> strings;
    int n = 0, m = 0;
    string t;
    cout << "number of strings: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        strings.push_back(t);
    }
    
    cout << "m: ";
    cin >> m;
    cout << "n: ";
    cin >> n;
    Solution sol;
    cout << sol.findMaxForm(strings, m, n);
    return 0;
}
/*给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。

如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ones-and-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
/*经典的背包问题可以使用二维动态规划求解，两个维度分别是物品和容量。这道题有两种容量，因此需要使用三维动态规划求解，三个维度分别是字符串、00 的容量和 11 的容量。*/
// 零一背包问题
// strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3