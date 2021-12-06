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
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */