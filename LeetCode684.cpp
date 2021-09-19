#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Solution {
public:
    int Find(vector<int>& parent, int index) {
        if (parent[index] != index) {
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }

    void Union(vector<int>& parent, int index1, int index2) {
        parent[Find(parent, index1)] = Find(parent, index2);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int nodesCount = edges.size();
        vector<int> parent(nodesCount + 1);
        for (int i = 1; i <= nodesCount; ++i) {
            parent[i] = i;
        }
        for (auto& edge: edges) {
            int node1 = edge[0], node2 = edge[1];
            if (Find(parent, node1) != Find(parent, node2)) {
                Union(parent, node1, node2);
            } else {
                return edge;
            }
        }
        return vector<int>{};
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
    Solution sol;
    child = sol.findRedundantConnection(grid);
    n = child.size();
    cout << "[";
    for (int i = 0; i < n - 1; i++){
        cout << child.at(i) << ",";
    }
    cout << child.at(n - 1) << "]";
    return 0;
    return 0;
}
// number of edges: 3
// 1 2
// 2 3
// 1 3
// [1,3]