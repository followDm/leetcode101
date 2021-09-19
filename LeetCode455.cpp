#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int numOfChildren = g.size(), numOfCookies = s.size();
        int count = 0;
        for (int i = 0, j = 0; i < numOfChildren && j < numOfCookies; i++, j++) {
            while (j < numOfCookies && g[i] > s[j]) {
                j++;
            }
            if (j < numOfCookies) {
                count++;
            }
        }
        return count;
    }
};

int main(){
    vector<int> children, cookies;
    int n = 0,t = 0;
    cout << "number of children:";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        children.push_back(t);
    }
    cout << "number of cookies:";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        cookies.push_back(t);
    }
    Solution sol;
    cout << sol.findContentChildren(children, cookies);
    return 0;
}
// number of children:3
// 1 2 3
// number of cookies:2
// 1 1
// 1