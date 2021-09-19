#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string x, string y) {
        int j = 0;
        for (int i = 0; i < y.length() && j < x.length(); i++)
            if (x[j] == y[i])
                j++;
        return j == x.length();
    }

    string findLongestWord(string s, vector<string> dictionary) {
        string max_str = "";
        for (string str: dictionary) {
            if (isSubsequence(str, s)) {
                if (str.length() > max_str.length() || (str.length() == max_str.length() && str.compare(max_str) < 0))
                    max_str = str;
            }
        }
        return max_str;
    }
};

int main(){
    vector<string> dictionary;
    string s;
    int n;
    string t;
    cout << "string: ";
    cin >> s;
    cout << "size of dictionary: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        dictionary.push_back(t);
    }
    Solution sol;
    cout << sol.findLongestWord(s, dictionary);
    return 0;
}

// 输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
// 输出："apple"