#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> memo;
    vector<int> beautifulArray(int N) {
        return f(N);
    }

    vector<int> f(int N) {
        if (memo.find(N) != memo.end())
            return memo.at(N);

        vector<int> ans(N);
        if (N == 1) {
            ans[0] = 1;
        } else {
            int t = 0;
            for (int x: f((N+1)/2))  // odds
                ans[t++] = 2*x - 1;
            for (int x: f(N/2))  // evens
                ans[t++] = 2*x;
        }
        memo.insert(std::make_pair(N, ans));
        return ans;
    }
};

int main(){
    vector<int> nums;
    int n = 0, t = 0, target;

    cout << "target: ";
    cin >> target;
    Solution sol;
    nums = sol.beautifulArray(target);
    n = nums.size();
    cout << "[";
    for (int i = 0; i < n - 1; i++){
        cout << nums.at(i) << ",";
    }
    cout << nums.at(n - 1) << "]";
    return 0;
}
// target: 4
// [1,3,2,4]