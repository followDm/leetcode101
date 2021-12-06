#include <vector>
#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    int countPrimes1(int n) {
        vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ans += 1;
                if ((long long)i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
    int countPrimes2(int n) {
        if (n <= 2)
            return 0;
        vector<int> isPrime(n, true);
        int i = 3, sqrtn = sqrt(n), count = n / 2;
        while (i <= sqrtn) {
            for (int j  = i * i; j < n; j += 2 * i) {
                if(isPrime[j]) {
                    --count;
                    isPrime[j] = false;
                }
            }
            do {
                i += 2;
            } while (i <= sqrtn && !isPrime[i]);
        }
        return count;
    }
    enum choose {GA, RE};
    int countPrimes(int n, choose c) {
        switch (c){
        case GA:
            return countPrimes1(n);
            break;
        case RE:
            return countPrimes2(n);
            break;
        default:
            return -1;
            break;
        }
    }
};

int main(){
    int n;
    cout << "n: ";
    cin >> n;
    
    Solution sol;
    cout << sol.countPrimes(n, sol.RE);
    return 0;
}
/*统计所有小于非负整数 n 的质数的数量。*/
// 埃式筛法
// n: 7
// 3