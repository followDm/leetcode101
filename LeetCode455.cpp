#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& children, vector<int>& cookies) {
        sort(children.begin(), children.end());
        sort(cookies.begin(), cookies.end());
        // 官网的代码看不懂
        int child = 0, cookie = 0;
        while (child < children.size() && cookie < cookies.size()){
            if(children[child] <= cookies[cookie])
                ++ child;
            ++cookie;
        }
        return child;
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
/*
假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。

对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/assign-cookies
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// number of children:3
// 1 2 3
// number of cookies:2
// 1 1
// 1