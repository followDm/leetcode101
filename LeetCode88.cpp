#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int tail = m + n - 1;
        int cur;
        while (p1 >= 0 || p2 >= 0) {
            if (p1 == -1) {
                cur = nums2[p2--];
            } else if (p2 == -1) {
                cur = nums1[p1--];
            } else if (nums1[p1] > nums2[p2]) {
                cur = nums1[p1--];
            } else {
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
    }
};

int main(){
    vector<int> nums1, nums2;
    int n = 0, m = 0, t = 0;
    cout << "number of m: ";
    cin >> m;
    cout << "number of n: ";
    cin >> n;
    cout << "nums1: ";
    for (int i = 1; i <= m + n; i++){
        cin >> t;
        nums1.push_back(t);
    }
    cout << "nums2: ";
    for (int i = 1; i <= n; i++){
        cin >> t;
        nums2.push_back(t);
    }
    Solution sol;
    sol.merge(nums1, m, nums2, n);
    cout << "[";
    for (int i = 0; i < m + n -1; i++){
        cout << nums1.at(i) << ",";
    }
    cout << nums1.at(m + n -1) << "]";
    return 0;
}
/**
 * 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * 输出：[1,2,2,3,5,6]
 * 解释：需要合并 [1,2,3] 和 [2,5,6] 。
 * 合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素
 */