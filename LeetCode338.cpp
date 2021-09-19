#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);
        for (int i = 1; i <= n; i++) {
            bits[i] = bits[i >> 1] + (i & 1);
        }
        return bits;
    }
};

int main(){
    vector<int> nums;
    int n = 0, t = 0, target;
    
    cout << "target: ";
    cin >> target;
    Solution sol;
    nums = sol.countBits(target);
    n = nums.size();
    cout << "[";
    for (int i = 0; i < n - 1; i++){
        cout << nums.at(i) << ",";
    }
    cout << nums.at(n - 1) << "]";
    return 0;
}
// target: 5
// [0,1,1,2,1,2]