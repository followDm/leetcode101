#include<vector>
#include<numeric>
#include<iostream>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n);
        for (int i = 0; i < n; i++) {
            if (i > 0 && ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }
        int right = 0, ret = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1 && ratings[i] > ratings[i + 1]) {
                right++;
            } else {
                right = 1;
            }
            ret += max(left[i], right);
        }
        return ret;
    }
};


int main(){
    vector<int> ratings;
    int n=0,t=0;
    cout << "number of children:";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        ratings.push_back(t);
    }
    Solution sol;
    cout << sol.candy(ratings);
    return 0;
}
// number of children:3
// 1 0 2
// 5