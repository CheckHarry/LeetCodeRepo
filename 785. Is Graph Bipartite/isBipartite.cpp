#include <vector>
using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;
    int n;
    // 当前连通分量数目
    int setCount;
    
public:
    UnionFind(int _n): n(_n), setCount(_n), parent(_n), rank(_n, 0) {
        for (int i = 0 ; i < n ; i ++)
            parent[i] = i;
    }
    
    int findset(int x) {
        if (parent[x] == x)
            return x;
        else
            return parent[x] = findset(parent[x]);
    }
    
    void unite(int x, int y) {
        int rx = findset(x) , ry = findset(y);
        if (rx == ry)
            return;
        else
        {
            if (rank[rx] < rank[ry])
                parent[rx] = ry;
            else if (rank[rx] == rank[ry])
            {
                parent[rx] = ry;
                rank[ry] ++;
            }
            else
            {
                parent[ry] = rx;
            }
            setCount --;
        }
    }
    
    bool connected(int x, int y) {
        return findset(x) == findset(y);
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        UnionFind s(graph.size());
        int count = 0;
        for (auto && adjs : graph){
            if(adjs.size() == 0) s.setCount --;
            for (int i = 0 ; i < adjs.size() ; i ++)
            {   
                if (s.connected(count , adjs[i])) return false;
                s.unite(adjs[0] , adjs[i]);
            }
            count ++;
            
        }
     
        return true;
    }
};