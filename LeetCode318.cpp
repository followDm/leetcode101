#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string> words) {
        unordered_map<int, int> hash;
        int ans = 0;
        for (const string& word : words){
            int mask = 0, size = word.size();
            for (const char& c : word){
                mask |= 1 << (c - 'a');
            }
            hash[mask] = max(hash[mask], size);
            for (const auto& [h_mask, h_len] : hash){
                if(!(mask & h_mask)){
                    ans = max(ans, size * h_len);
                }
            }
            
        }
        return ans;
    }
};

int main(){
    vector<string> words;
    int n;
    string t;
    cout << "size of words: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t;
        words.push_back(t);
    }
    Solution sol;
    cout << sol.maxProduct(words);
    return 0;
}
/*给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-of-word-lengths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// size of words: 7
// a ab abc d cd bcd abcd
// 4