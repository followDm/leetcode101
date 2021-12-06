#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    string addStrings1(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans.push_back('0' + result % 10);
            add = result / 10;
            i -= 1;
            j -= 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string addStrings2(string num1, string num2) {
        string output("");
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int oneLen = num1.size(), towLen = num2.size();
        if (oneLen <= towLen) {
            swap(num1, num2);
            swap(oneLen, towLen);
        }
        int addbit = 0;
        for (int i = 0; i < towLen; ++i) {
            int cur_sum = (num1[i] - '0') + (num2[i] - '0') + addbit;
            output += to_string((cur_sum) % 10);
            addbit = cur_sum < 10 ? 0 : 1;
        }
        for (int i = towLen; i < oneLen; ++i) {
            int cur_sum = (num1[i] - '0') + addbit;
            output += to_string((cur_sum) % 10);
            addbit = cur_sum < 10 ? 0 : 1;
        }
        if(addbit) {
            output += "1";
        }
        reverse(output.begin(), output.end());
        return output;
    }
    enum choose {GA, RE};
    string addStrings(string num1, string num2, choose c) {
        switch (c){
        case GA:
            return addStrings1(num1, num2);
            break;
        case RE:
            return addStrings2(num1, num2);
            break;
        default:
            return "";
            break;
        }
    }    
};

int main(){
    string s1, s2;
    cout << "s1: ";
    cin >> s1;
    cout << "s2: ";
    cin >> s2;
    Solution sol;
    cout << sol.addStrings(s1, s2, sol.RE);
    return 0;
}
/*给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。

你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// s1: 123456789
// s2: 987654321
// 1111111110