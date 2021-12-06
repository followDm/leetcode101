#include<vector>
#include<random>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> psum;

    Solution(vector<int> weights): psum(move(weights)) {
        partial_sum(psum.begin(), psum.end(), psum.begin());
    }

    int pickIndex() {
        int pos = (rand() % psum.back()) + 1;
        return lower_bound(psum.begin(), psum.end(), pos) - psum.begin();
    }
};

int main(){
    vector<int> nums = {1,2,4,3};
    int n = 0, t = 0, target;
    // cout << "number of nums: ";
    // cin >> n;
    // for (int i = 1; i <= n; i++){
    //     cin >> t;
    //     nums.push_back(t);
    // }
    
    Solution sol = Solution(nums);
    cout << sol.pickIndex();
    return 0;
}
/*给你一个 下标从 0 开始 的正整数数组 w ，其中 w[i] 代表第 i 个下标的权重。

请你实现一个函数 pickIndex ，它可以 随机地 从范围 [0, w.length - 1] 内（含 0 和 w.length - 1）选出并返回一个下标。选取下标 i 的 概率 为 w[i] / sum(w) 。

例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 （即，25%），而选取下标 1 的概率为 3 / (1 + 3) = 0.75（即，75%）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/random-pick-with-weight
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// number of nums: 4
// 1 2 3 4
// 3