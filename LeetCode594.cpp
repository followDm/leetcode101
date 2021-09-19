#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public: 
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> map;
        int res = 0, t;
        for (int num: nums) {
            if(map.find(num) != map.end()){
                map.find(num)->second ++;
            } else {
                map.insert(std::make_pair(num, 1));
            }
            if (map.find(num + 1) != map.end())
                res = max(res, map.at(num) + map.at(num + 1));
            if (map.find(num - 1) != map.end())
                res = max(res, map.at(num) + map.at(num - 1));
        }
        return res;
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
    
    Solution sol;
    cout << sol.findLHS(nums);
    return 0;
}
// number of nums: 8
// 1 3 2 2 5 2 3 7
// 5