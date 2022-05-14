#include <vector>
using namespace std;






class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v{};
        dfs(v , n ,  k , 0 );
        return ans;
    }
    void dfs(vector<int> &v , int n , int k , int sum ){
        if (v.size() == k && sum == n)
        {
            ans.push_back(v);
            return ;
        }

        for (int i = (v.empty() ? 0 : v.back()) + 1 ; i <= 9 ; i ++)
        {
            if (sum + i <= n)
            {
                v.push_back(i);
                dfs(v , n  , k , sum + i);
                v.pop_back();
            }
            else
                break;
        }
    }
    

};