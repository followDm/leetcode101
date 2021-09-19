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
// 每个字符出现次数相同
// string1: hello
// string2: wrold
// false