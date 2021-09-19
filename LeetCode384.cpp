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