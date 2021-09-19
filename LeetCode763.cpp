#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26];
        int length = s.size();
        for (int i = 0; i < length; i++) {
            last[s[i] - 'a'] = i;
        }
        vector<int> partition;
        int start = 0, end = 0;
        for (int i = 0; i < length; i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
};

int main(){
    vector<int> child;
    string points;
    cout << "chars: ";
    cin >> points;
    Solution sol;
    child = sol.partitionLabels(points);
    cout << "[";
    for (int i = 0; i < child.size()-1; i++){
        cout << child.at(i) << ",";
    }
    cout << child.at(child.size()-1) << "]";
    return 0;
}

/**
 * 输入：S = "ababcbacadefegdehijhklij"
 * 输出：[9,7,8]
 */