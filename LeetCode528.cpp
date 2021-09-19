#include<vector>
#include<random>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> psum;
    int tot = 0;
    //c++11 random integer generation
    mt19937 rng{random_device{}()};
    uniform_int_distribution<int> uni;

    Solution(vector<int> w) {
        for (int x : w) {
            tot += x;
            psum.push_back(tot);
        }
        uni = uniform_int_distribution<int>{0, tot - 1};
    }

    int pickIndex() {
        int targ = uni(rng);

        int lo = 0, hi = psum.size() - 1;
        while (lo != hi) {
            int mid = (lo + hi) / 2;
            if (targ >= psum[mid])
                lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};

int main(){
    vector<int> nums;
    int n = 0, t = 0, target;
    cout << "number of nums: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        nums.push_back(t);
    }
    
    Solution sol = Solution(nums);
    cout << sol.pickIndex();
    return 0;
}
// number of nums: 4
// 1 2 3 4
// 3