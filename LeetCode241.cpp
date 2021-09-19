#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> vec1, vec2, res;
        int n = input.size();
        int flag = 0;
        for(int i=0; i<n; i++){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                flag = 1;
                vec1 = diffWaysToCompute(string(input, 0, i));
                vec2 = diffWaysToCompute(string(input, i+1, n-i-1)); 
                for(int v1:vec1){
                    for(int v2:vec2){
                        if(input[i] == '+') res.push_back(v1+v2);
                        if(input[i] == '-') res.push_back(v1-v2);
                        if(input[i] == '*') res.push_back(v1*v2);
                    }
                }
            }
        }
        if(flag==0) return {std::stoi(input)};
        return res;
    }
};

int main(){
    vector<int> nums;
    int n = 0, t = 0;
    string target;
    cout << "target: ";
    cin >> target;
    Solution sol;
    nums = sol.diffWaysToCompute(target);
    n = nums.size();
    cout << "[";
    for (int i = 0; i < n - 1; i++){
        cout << nums.at(i) << ",";
    }
    cout << nums.at(n - 1) << "]";
    return 0;
}
// target: 2*3-2
// [2,4]