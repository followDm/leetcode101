#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans.push_back('0' + result % 10);
            add = result / 10;
            i -= 1;
            j -= 1;
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
    cout << sol.addStrings(s1, s2);
    return 0;
}
// s1: 123456789
// s2: 987654321
// 1111111110