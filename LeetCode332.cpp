#include <vector>
#include<iostream>
#include<unordered_map>
#include<queue>
#include<set>
#include<algorithm>
#include<cstdlib>
#include<stack>
using namespace std;

class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;
    vector<string> stk;
    void dfs(const string& curr) {
        while (vec.count(curr) && vec[curr].size() > 0) {
            string tmp = vec[curr].top();
            vec[curr].pop();
            dfs(move(tmp));
        }
        stk.emplace_back(curr);
    }

    vector<string> findItinerary1(vector<vector<string>>& tickets, string st) {
        for (auto& it : tickets) {
            vec[it[0]].emplace(it[1]);
        }
        dfs(st);

        reverse(stk.begin(), stk.end());
        return stk;
    }
    vector<string> findItinerary2(vector<vector<string>>& tickets, string st) {
        vector<string> ans;
        if (tickets.empty()) {
            return ans;
        }
        unordered_map<string, multiset<string>> hash;
        for (const auto & ticket: tickets) {
            hash[ticket[0]].insert(ticket[1]);
        }
        stack<string> s;
        s.push(st);
        while (!s.empty()) {
            string next = s.top();
            if (hash[next].empty()) {
                ans.push_back(next);
                s.pop();
            } else {
                s.push(*hash[next].begin());
                hash[next].erase(hash[next].begin());
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    enum choose {GA, RE};
    auto findItinerary(vector<vector<string>>& tickets, string st, choose c) {
        switch (c){
        case GA:
            return findItinerary1(tickets, st);
            break;
        case RE:
            return findItinerary2(tickets, st);
            break;
        default:
            vector<string> ans;
            return ans;
            break;
        }
    }
};

int main(){
    vector<string> airports = {"JFK","MUC","LHR","SFO","SJC"};
    vector<vector<string>> tickets;
    vector<string> child;
    int rows = 0, columns = 0, n = 0;
    int t1, t2;
    cout << "number of tickets: ";
    cin >> rows;
    srand(rows);
    for (int i = 1; i <= rows; i++){ 
        t1 = rand() % 5;
        t2 = rand() % 5;
        if(t1 ^ t2 == 0) {
            // 我想的是，实际也不会有机场内部的航班，当然这样做也不知万无一失的
            t2 = rand() % 5;
        }
        child.push_back(airports[t1]);
        child.push_back(airports[t2]);
        
        tickets.push_back(child);
        child.clear();
    }
    Solution sol;
    child = sol.findItinerary(tickets, "JFK", sol.RE);
    n = child.size();
    cout << "[";
    for (int i = 0; i < n - 1; i++){
        cout << child.at(i) << ",";
    }
    cout << child.at(n - 1) << "]";

    return 0;
}
/*给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。

所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。

例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reconstruct-itinerary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
// 多重集合和映射
// number of tickets: 4
// MUC LHR
// JFK MUC
// SFO MUC
// LHR SFO
// [JFK,MUC,LHR,SFO,MUC]