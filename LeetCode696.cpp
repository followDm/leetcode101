#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    // 没看懂
    int countBinarySubstrings1(string s) {
        int ptr = 0, n = s.size(), last = 0, ans = 0;
        while (ptr < n) {
            char c = s[ptr];
            int count = 0;
            while (ptr < n && s[ptr] == c) {
                ++ptr;
                ++count;
            }
            ans += min(count, last);
            last = count;
        }
        return ans;
    }
    int countBinarySubstrings2(string s) {
        int pre = 0, cur = 1, count = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) {
                ++cur;
            } else {
                pre = cur;
                cur = 1;
            }
            if (pre >= cur) {
                ++count;
            }
        }
        
        return count;
    }
    enum choose {GA, RE};
    auto countBinarySubstrings(string s, choose c) {
        switch (c){
        case GA:
            return countBinarySubstrings1(s);
            break;
        case RE:
            return countBinarySubstrings2(s);
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
    cout << sol.countBinarySubstrings(s, sol.GA);
    return 0;
}
/*给定一个字符串 s，计算具有相同数量 0 和 1 的非空（连续）子字符串的数量，并且这些子字符串中的所有 0 和所有 1 都是连续的。

重复出现的子串要计算它们出现的次数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-binary-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// string: 00110011
// 6