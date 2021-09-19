#include<iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        return [](unsigned int i){return !(i & (i+1));}((n ^ (n>>1)));
    }
};

int main(){
    int n = 0, t = 0;
    cout << "number: ";
    cin >> n;
    
    Solution sol;
    cout << boolalpha << sol.hasAlternatingBits(n);
    return 0;
}
// number: 13
// false