#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    // Manacher算法
    int countSubstrings1(string s) {
        int n = s.size();
        string t = "$#";
        for (const char &c: s) {
            t += c;
            t += '#';
        }
        n = t.size();
        t += '!';

        auto f = vector <int> (n);
        int iMax = 0, rMax = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            // 初始化 f[i]
            f[i] = (i <= rMax) ? min(rMax - i + 1, f[2 * iMax - i]) : 1;
            // 中心拓展
            while (t[i + f[i]] == t[i - f[i]]) ++f[i];
            // 动态维护 iMax 和 rMax
            if (i + f[i] - 1 > rMax) {
                iMax = i;
                rMax = i + f[i] - 1;
            }
            // 统计答案, 当前贡献为 (f[i] - 1) / 2 上取整
            ans += (f[i] / 2);
        }

        return ans;
    }
    int countSubstrings2(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            count += extendSubstring(s, i, i);
            count += extendSubstring(s, i, i + 1);
        }
        return count;
    }
    int extendSubstring(string s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            --l;
            ++r;
            ++count;
        }
        return count;        
    }
    enum choose {GA, RE};
    auto countSubstrings(string s, choose c) {
        switch (c){
        case GA:
            return countSubstrings1(s);
            break;
        case RE:
            return countSubstrings2(s);
            break;
        default:
            return 0;
            break;
        }
    }
};

int main(){
    string s;
    cout << "string: ";
    cin >> s;
    
    Solution sol;
    cout << sol.countSubstrings(s, sol.RE);
    return 0;
}
/*给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。

回文字符串 是正着读和倒过来读一样的字符串。

子字符串 是字符串中的由连续字符组成的一个序列。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindromic-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// string: aaa
// 6