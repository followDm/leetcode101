#include<iostream>
#include<tuple>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int a = 0, b = 1, c;
        for (int i = 1; i <= n; ++i) {
            c = 0;
            if (s[i - 1] != '0') {
                c += b;
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
                c += a;
            }
            tie(a, b) = {b, c};
        }
        return c;
    }
};

int main(){
    string s;
    cout << "string: ";
    cin >> s;
    
    Solution sol;
    cout << boolalpha << sol.numDecodings(s);
    return 0;
}
// string: 1226
// 3