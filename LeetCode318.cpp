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
// size of words: 7
// a ab abc d cd bcd abcd
// 4