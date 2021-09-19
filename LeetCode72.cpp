#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        if (n * m == 0) 
            return n + m;

        int D[n + 1][m + 1];
        int i, j, left, down, left_down;
        for (i = 0; i < n + 1; i++) {
            D[i][0] = i;
        }
        for (j = 0; j < m + 1; j++) {
            D[0][j] = j;
        }
        for (i = 1; i < n + 1; i++) {
            for (j = 1; j < m + 1; j++) {
                left = D[i - 1][j] + 1;
                down = D[i][j - 1] + 1;
                left_down = D[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1])
                    left_down += 1;
                D[i][j] = min(left, min(down, left_down));
            }
        }
        return D[n][m];
    }
};

int main(){
    string text1, text2;
    cout << "text1: ";
    cin >> text1;
    cout << "text2: ";
    cin >> text2;
    
    Solution sol;
    cout << boolalpha << sol.minDistance(text1, text2);
    return 0;
}
// text1: hello
// text2: world
// 4