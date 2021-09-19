#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        //重载priority_queue的比较函数，priority_queue默认是大顶堆，重载的是<号
        //默认情况下如果左边参数大于右边参数，则说明左边形参的优先级低于右边形参，会将左边的放到后面
        //构建小顶堆时，我们实现一个>号的判断即可，大于返回true，优先级低，被放到后面，则小的会放前面
        struct cmp {
            bool operator () (const vector<int> &a, const vector<int> &b) {
                return a[2] > b[2];
            }
        };
        int selected = 0, ans = 0;
        //构建点和cost的集合关系，本质是个三维数组，第一维是起点，二维是<终点、开销>
        vector<vector<pair<int,int>>> edgs(N+1,vector<pair<int,int>>());
        //构建小顶堆，将最合适的点放在最前面
        priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
        vector<int> visit(N+1, 0);
        //初始化边集合
        for(auto re : connections){
            edgs[re[0]].push_back(make_pair(re[1],re[2]));
            edgs[re[1]].push_back(make_pair(re[0],re[2]));
        }
        //本次选择1为起点，如果1点没有变，则1永远是孤岛。本次选择1为起点
        if(edgs[1].size() == 0){
            return -1;
        }

        selected = 1;
        visit[1] = true;
        //起点1所在的边放入小顶堆
        for(int i = 0;i < edgs[1].size(); ++i){
            pq.push(vector<int>({1,edgs[1][i].first,edgs[1][i].second}));
        }
        //遍历小顶堆
        while(!pq.empty()) {
            auto curr = pq.top();pq.pop();
            if(!visit[curr[1]]){
                visit[curr[1]] = true;
                ans += curr[2];
                 //依次取出cost最小的边所在的点加入集合
                for(auto e : edgs[curr[1]]){
                    pq.push(vector<int>({curr[1],e.first,e.second}));
                }
                selected++;
                if(selected == N){ //如果N个节点都在时，则结束循环
                    return ans;
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> grid;
    vector<int> child;
    int rows = 0, columns = 0, t = 0, n = 0;
    cout << "number of edges: ";
    cin >> rows;
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= 3; j++){
            cin >> t;
            child.push_back(t);
        }
        grid.push_back(child);
        child.clear();
    }
    cout << "number of points: ";
    cin >> columns;
    
    Solution sol;
    cout << sol.minimumCost(columns, grid);
    
    return 0;
}
// number of edges: 2
// 1 2 3
// 3 4 4
// number of points: 4
// -1