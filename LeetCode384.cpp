#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> copy;
    vector<int> numbers;
    Solution(vector<int>& nums): numbers(nums), copy(nums) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return numbers;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = 0; i < copy.size(); ++i) {
            swap(copy[i], copy[rand() % copy.size()]);
        }
        return copy;
    }
};

int main(){
    vector<int> nums {1, 2, 3, 4, 5}, result;
    Solution solution(nums);
    result = solution.shuffle();
    for (auto item: result) cout << item << " ";
    cout << endl;
    result = solution.shuffle();
    for (auto item: result) cout << item << " ";
    cout << endl;
    return 0;
}
/*给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。

实现 Solution class:

Solution(int[] nums) 使用整数数组 nums 初始化对象
int[] reset() 重设数组到它的初始状态并返回
int[] shuffle() 返回数组随机打乱后的结果

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shuffle-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// 忘了代码哪里来的了，不过我看着也特别简单容易懂