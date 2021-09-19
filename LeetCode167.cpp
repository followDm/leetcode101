#include<vector>
#include<numeric>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) {
                return {low + 1, high + 1};
            } else if (sum < target) {
                ++low;
            } else {
                --high;
            }
        }
        return {-1, -1};
    }
};

int main(){
    vector<int> numbers;
    int n=0,t=0;
    cout << "number of nums: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        numbers.push_back(t);
    }
    cout << "number of target: ";
    cin >> n;
    Solution sol;
    numbers = sol.twoSum(numbers, n);
    cout << "[" << numbers[0] << "," << numbers[1] << "]";
    return 0;
}
/**
 * 输入：numbers = [2,7,11,15], target = 9
 * 输出：[1,2]
 * 解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 */