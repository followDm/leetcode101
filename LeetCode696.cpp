#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
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
};

int main(){
    string s;
    cout << "string: ";
    cin >> s;
    
    Solution sol;
    cout << sol.countBinarySubstrings(s);
    return 0;
}

// string: 00110011
// 6