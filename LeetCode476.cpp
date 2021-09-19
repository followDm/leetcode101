#include<iostream>
using namespace std;
class Solution {
public:
    int findComplement(int num) {
        int cnt=0;
        for(int i=0;i<32;i++){
            if((num>>i)!=0)cnt++;
            else break;
        }
        int mask=((long)1<<cnt)-1;
        return num^mask;
    }
};

int main(){
    int n = 0, t = 0;
    cout << "number: ";
    cin >> n;
    
    Solution sol;
    cout << sol.findComplement(n);
    return 0;
}
// number: 5
// 2