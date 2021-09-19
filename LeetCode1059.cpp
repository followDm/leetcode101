#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
    	vector<bool> visited(n, false);
    	vector<vector<int>> m(n);
    	for(auto& e : edges)
    		m[e[0]].push_back(e[1]);
    	if(!m[destination].empty())
    		return false;                       //终点后面还有路径
		return dfs(m,visited,source,destination);
    }
    bool dfs(vector<vector<int>>& m, vector<bool>& visited, int cur, int destination) {
    	if(m[cur].size()==0 && cur != destination)
    		return false;                       //到达一个终点，但不是目标点
    	for(int next : m[cur]){
    		if(visited[next])                   //有环访问过了
    			return false;
    		visited[next] = true;               //访问
    		if(!dfs(m, visited, next, destination))
    			return false;
    		visited[next] = false;              //回溯
    	}
        return true;
    }
};

int main(){
    vector<vector<int>> grid;
    vector<int> child;
    int rows = 0, columns = 0, t = 0, n = 0;
    cout << "number of edges: ";
    cin >> rows;
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= 2; j++){
            cin >> t;
            child.push_back(t);
        }
        grid.push_back(child);
        child.clear();
    }
    cout << "number of points: ";
    cin >> columns;
    cout << "source: ";
    cin >> t;
    cout << "destination: ";
    cin >> n;
    Solution sol;
    cout << boolalpha << sol.leadsToDestination(columns, grid, t, n);
    
    return 0;
}
// number of edges: 4
// 0 1
// 0 2
// 1 3
// 2 3
// number of points: 4
// source: 0
// destination: 3
// true
// ---------------------------
// number of edges: 3
// 0 1
// 1 1
// 1 2
// number of points: 3
// source: 0
// destination: 2
// false