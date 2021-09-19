#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int m = flowerbed.size();
        int prev = -1;
        for (int i = 0; i < m; ++i) {
            if (flowerbed[i] == 1) {
                if (prev < 0) {
                    count += i / 2;
                } else {
                    count += (i - prev - 2) / 2;
                }
                prev = i;
            }
        }
        if (prev < 0) {
            count += (m + 1) / 2;
        } else {
            count += (m - prev - 1) / 2;
        }
        return count >= n;
    }
};
int main(){
    vector<int> flowerbed;
    int n = 0, t = 0;
    cout << "number of flowerbeds: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        flowerbed.push_back(t);
    }
    cout << "number of flowers: ";
    cin >> n;
    Solution sol;
    cout << sol.canPlaceFlowers(flowerbed, n);
    return 0;
}
/**
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: false/0
 */
