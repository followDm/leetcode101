#include<vector>
#include<iostream>
#include<string>
#include<numeric>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        // s = s.replace(" ", "");
        if (s.length() == 0) 
            return 0;
        vector<long> stk;
        char sign = '+';
        int pre = 0, i = 0;
        while (i < s.length()) {
            char ch = s.at(i);
            
            if (isdigit(ch)) {
                pre = pre*10+(ch-'0');
            }

            if (ch == '(') {
                int j = findClosing(s.substr(i));
                pre = calculate(s.substr(i+1, i+j));
                i += j;
            }

            if (i == s.length()-1 || !isdigit(ch) && s[i] != ' ') {
                switch (sign) {
                    case '+':
                        stk.push_back(pre);
                        break;
                    case '-':
                        stk.push_back(-pre);
                        break;
                    case '*':
                        stk.back() *= pre; 
                        break;
                    case '/':
                        stk.back() /= pre;
                        break;
                }
                pre = 0;
                sign = ch;
            } 
            i++;
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
    
    int findClosing(string s) {
        int level = 0, i = 0;
        for (i = 0; i < s.length(); i++) {
            if (s.at(i) == '(') level++;
            else if (s.at(i) == ')') {
                level--;
                if (level == 0) break;
            } else continue;
        }
        return i;
    }
};

int main(){
    string s;
    cout << "string: ";
    getline(cin, s);
    
    Solution sol;
    cout << sol.calculate(s);
    return 0;
}
// string: 5 * 4 / 2 - 3 + 1
// 8
