#include <vector>
#include <queue>
using namespace std;


int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> edges_list(n + 1 , vector<pair<int,int>> ());
        vector<int> distance(n + 1 , INT_MAX);
        auto g = [](const pair<int , int> & x , const pair<int , int> & y){return x.second > y.second;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(g)> q(g);
      
        distance[k] = 0;
        q.emplace(k , 0);
        for (auto edge : times)
        {
            edges_list[edge[0]].push_back({edge[1] , edge[2]});
        }
        while (!q.empty())
        {
            auto top = q.top();
            q.pop();
            if (distance[top.first] < top.second)
                continue;
            
            for (auto && n : edges_list[top.first])
            {
                int nd = distance[top.first] + n.second;
                if (distance[n.first] > nd)
                {
                    distance[n.first] = nd;
                    q.emplace(n.first , distance[n.first]);
                }
            }
        }
        
        int ans = *max_element(distance.begin() + 1, distance.end());
        return ans == INT_MAX ? -1 : ans;
    }