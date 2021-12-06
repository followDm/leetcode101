#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
#include<cstdlib>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < n; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() <= i - k) {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

int main(){
    vector<int> nums;
    int n = 0, t = 0, k;
    cout << "number of nums: ";
    cin >> n;
    srand(n);
    // 直接用随机数了
    for (int i = 1; i <= n; i++){
        // cin >> t;
        // 限制范围
        t = rand() % 10 + 1;
        nums.push_back(t);
    }
    
    cout << "k: ";
    cin >> k;
    Solution sol;
    nums = sol.maxSlidingWindow(nums, k);
    // 结果的长度不等于输入的长度
    n = nums.size();
    cout << "[";
    for (int i = 0; i < n - 1; i++){
        cout << nums.at(i) << ",";
    }
    cout << nums.at(n - 1) << "]";
    return 0;
}
/**给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-window-maximum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// 双端队列
// number of nums: 8
// 1 3 -1 -3 5 3 6 7
// k: 3
// [3,3,5,5,6,7]