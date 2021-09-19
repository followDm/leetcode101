#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void swap(vector<int> list, int i, int pivot_index) {
        int temp = list[i];
        list[i] = list[pivot_index];
        list[pivot_index] = temp;
    }
    int partition(vector<int> list, int left, int right) {
        int pivotValue = list[right];
        int i = left;
        for (int j = left; j <= right; j++) {
            if (list[j] < pivotValue) {
                swap(list, i, j);
                i++;
            }
        }
        swap(list, right, i);
        return i;
    }
    int select(vector<int> list, int left, int right, int k) {
        if (left == right) {
            return list[left];
        }
        int pivotIndex = partition(list, left, right);
        if (k == pivotIndex) {
            return list[k];
        } else if (k < pivotIndex) {
            return select(list, left, pivotIndex - 1, k);
        } else {
            return select(list, pivotIndex + 1, right, k);
        }
    }
    int minMoves2(vector<int> nums) {
        int sum = 0;
        int median = select(nums, 0, nums.size() - 1, nums.size() / 2);

        for (int num : nums) {
            sum += abs(median - num);
        }
        return sum;
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
    cout << sol.minMoves2(nums);
    return 0;
}
// number of nums: 8
// 2 5 9 0 1 4 5 3
// 23