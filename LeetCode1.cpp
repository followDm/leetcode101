#include<iostream>
#include<unordered_map>
#include<vector>
#include<cstdlib>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

int main(){
    vector<int> nums;
    int n = 0, t = 0, target;
    cout << "number of nums: ";
    cin >> n;
    srand(n);
    for (int i = 1; i <= n; i++){
        t = rand() % 10 + 1;
        nums.push_back(t);
    }
    
    cout << "target: ";
    cin >> target;
    Solution sol;
    auto res = sol.twoSum(nums, target);
    n = res.size();
    cout << "[";
    for (int i = 0; i < n - 1; i++){
        cout << res.at(i) << ",";
    }
    cout << res.at(n - 1) << "]";
    return 0;
}
/*给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// 哈希表散列表
// number of nums: 4
// 2 7 11 15
// target: 9
// [0,1]