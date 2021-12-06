#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q; 
            q = r; 
            r = p + q;
        }
        return r;
    }
};

int main(){
    int n;
    cout << "n: ";
    cin >> n;
    
    Solution sol;
    cout << sol.climbStairs(n);
    return 0;
}
/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。*/
// 官方有矩阵幂的计算方式
// 最后试了试n=100等的数字，当n比较大的时候，中间的部分数字由于超出了整数或者长整数的表示范围，出现负数不可避免
// 一维动态规划
// n: 3
// 3