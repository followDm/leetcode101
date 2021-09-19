#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = max(a.size(), b.size()), carry = 0;
        for (size_t i = 0; i < n; ++i) {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }

        if (carry) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main(){
    string s1, s2;
    cout << "s1: ";
    cin >> s1;
    cout << "s2: ";
    cin >> s2;
    Solution sol;
    cout << sol.addBinary(s1, s2);
    return 0;
}
// s1: 10000
// s2: 10010
// 100010