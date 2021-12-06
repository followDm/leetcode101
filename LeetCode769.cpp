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
/*数组arr是[0, 1, ..., arr.length - 1]的一种排列，我们将这个数组分割成几个“块”，并将这些块分别进行排序。之后再连接起来，使得连接的结果和按升序排序后的原数组相同。

我们最多能将数组分成多少块？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-chunks-to-make-sorted
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// number of nums: 5
// 4 0 1 2 3
// 1