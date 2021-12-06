#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> table(26, 0);
        for (auto& ch: s) {
            table[ch - 'a']++;
        }
        for (auto& ch: t) {
            table[ch - 'a']--;
            if (table[ch - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main(){
    string s1, s2;
    cout << "string1: ";
    cin >> s1;
    cout << "string2: ";
    cin >> s2;
    Solution sol;
    cout << boolalpha << sol.isAnagram(s1, s2);
    return 0;
}
/*给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-anagram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// 每个字符出现次数相同
// string1: hello
// string2: wrold
// false