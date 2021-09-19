#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        int chunks = 0;
        int cur_max = 0;
        for (int i = 0; i < nums.size(); i++){
            cur_max = max(cur_max, nums[i]);
            if(cur_max == i){
                ++chunks;
            }
        }
        return chunks;
    }
};

int main(){
    vector<int> nums;
    int n = 0, t = 0;
    cout << "number of nums: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        nums.push_back(t);
    }

    Solution sol;
    cout << sol.maxChunksToSorted(nums);
    return 0;
}
// number of nums: 5
// 4 0 1 2 3
// 1