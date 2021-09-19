#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.size() == 0 || k <= 0)
            return 0;
        unordered_map<char, int > m;
        int l = 0, r = 0;   // 滑动窗口左右指针
        int maxLen = 1;     // 最大长度
        int count = 0;
        while(r < s.size()){
            if (m[s[r]] == 0)
                count ++;
            m[s[r]] += 1;
            r++;
            // 左指针移动减小
            while (count > k){
                if(m[s[l]] == 1)
                    count--;
                m[s[l]] -= 1;
                l++;
            }
            maxLen = max(maxLen, r - l);
        }
        return maxLen;
    }
};

int main(){
    string s;
    int k;
    cout << "string: ";
    cin >> s;
    cout << "k: ";
    cin >> k;
    Solution sol;
    cout << boolalpha << sol.lengthOfLongestSubstringKDistinct(s, k);
    return 0;
}

// 输入: s = "eceba", k = 2
// 输出: 3
// 解释: 则 T 为 "ece"，所以长度为 3。