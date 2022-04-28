#include <unordered_set>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <tuple>
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
        }
    }
    
    bool connected(int x, int y) {
        return findset(x) == findset(y);
    }
};




class Solution {
public:
    vector<int> rank , parent;



    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size() , m = heights[0].size();
        vector<tuple<int,int,int>> edges;
        for (int i = 0 ; i < n ; i ++)
        {
            for (int j = 0 ; j < m ; j ++)
            {
                int id = m*i + j;
                if (i < n - 1)
                    edges.emplace_back(id , id + m , abs(heights[i][j] - heights[i + 1][j]));
                if (j < m - 1)
                    edges.emplace_back(id , id + 1 , abs(heights[i][j] - heights[i][j + 1]));
            }
        }
        sort(edges.begin() , edges.end() , [](const auto& x , const auto& y){
            return get<2>(x) < get<2>(y);
        });

        UnionFind uf(m * n);
        int ans = 0;
        for (const auto [x, y, v]: edges) {
            uf.unite(x, y);
            if (uf.connected(0, m * n - 1)) {
                ans = v;
                break;
            }
        }
        return ans;

    }
};