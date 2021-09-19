#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber > 0) {
            --columnNumber;
            ans += columnNumber % 26 + 'A';
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    string s;
    int num;
    cout << "num: ";
    cin >> num;
    
    Solution sol;
    cout << sol.convertToTitle(num);
    return 0;
}
// num: 28
// AB