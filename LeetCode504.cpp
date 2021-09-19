#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if(num==0)
            return "0";
        bool is_negative = num < 0;
        if(is_negative){
            num = -num;
        }
        string ans;
        int a, b;
        while(num){
            a = num / 7, b = num % 7;
            ans = to_string(b) + ans;
            num = a;
        }
        return is_negative ? "-" + ans : ans;
    }
};

int main(){
    int n;
    cout << "n: ";
    cin >> n;
    
    Solution sol;
    cout << sol.convertToBase7(n);
    return 0;
}
// n: 100
// 202