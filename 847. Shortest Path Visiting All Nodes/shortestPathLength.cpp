#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;









int shortestPathLength(vector<vector<int>>& graph) {
    queue<vector<int>> Q;
    vector<vector<int>> seen(graph.size() , vector<int> (1 << graph.size() , 0));
    for (int i = 0 ; i < graph.size() ; i ++) {
        Q.push(vector<int> {i , 0 , 1 << i});
        seen[i][1 << i] = 1;
    }
    while (!Q.empty()) {
        vector<int> front = std::move(Q.front());
        Q.pop();
        if (front[2] == (1 << graph.size()) - 1) return front[1];
        for (int node : graph[front[0]]) {  
            if (seen[node][front[2] | 1 << node] == 0){
                seen[node][front[2] | 1 << node] = 1;
                Q.push({node , front[1] + 1 , front[2] | 1 << node});
            }
        }
    }
    return 0;
}