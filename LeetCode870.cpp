#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> temp;
        sort(A.begin(), A.end());
        for (size_t i = 0; i < B.size(); ++i) {
            size_t j = 0;
            bool flag = false;
            while (j < A.size()) {
                if (A[j] > B[i]) {
                    temp.push_back(A[j]);
                    A.erase(A.begin() + j);
                    flag = true;
                    break;
                }
                ++j;
            }
            if (!flag) {
                temp.push_back(A[0]);
                A.erase(A.begin());
            }
        }
        return temp;
    }
};

int main(){
    int n1 = 0, n2 = 0, t = 0;
    cout << "number of num1: ";
    cin >> n1;
    vector<int> nums1;
    for (int i = 1; i <= n1; i++){
        cin >> t;
        nums1.push_back(t);
    }
    cout << "number of num2: ";
    cin >> n2;
    vector<int> nums2;
    for (int i = 1; i <= n2; i++){
        cin >> t;
        nums2.push_back(t);
    }
    Solution sol;
    vector<int>  temp;
    temp = sol.advantageCount(nums1, nums2);
    for (auto& i : temp) {
        cout << i << " ";
    }
    cout << endl;
    system("PAUSE");
    return 0;
}