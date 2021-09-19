#include <vector>
#include<time.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int rand10() {
        int a, b, idx;
        while (true) {
            a = rand7();
            b = rand7();
            idx = b + (a - 1) * 7;
            if (idx <= 40)
                return 1 + (idx - 1) % 10;
            a = idx - 40;
            b = rand7();
            // get uniform dist from 1 - 63
            idx = b + (a - 1) * 7;
            if (idx <= 60)
                return 1 + (idx - 1) % 10;
            a = idx - 60;
            b = rand7();
            // get uniform dist from 1 - 21
            idx = b + (a - 1) * 7;
            if (idx <= 20)
                return 1 + (idx - 1) % 10;
        }
    }
    int rand7(){
        srand((int)time(NULL)); //参考
        return rand()%7 + 1;
    }
};

int main(){
    vector<int> nums;
    int n = 0, t = 0, target;
    cout << "target: ";
    cin >> target;
    Solution sol;
    cout << "[";
    for (int i = 0; i < target - 1; i++){
        cout << sol.rand10() << ",";
    }
    cout << nums.at(n - 1) << "]";
    return 0;
}