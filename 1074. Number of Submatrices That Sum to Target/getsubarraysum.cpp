#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    
    int getsubarraysum(vector<int> &nums , int target)
    {
        unordered_map<int , int> count;
        int ans = 0;
        int s = 0;
        count[0] = 1;
        for (int i = 0 ; i < nums.size() ; i ++)
        {
            s += nums[i];
            if (count.find(s - target) != count.end())
                ans += count[s - target];
            count[s] += 1;
        }
        return ans;
    }
    
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
        
        for (int i = 0 ; i < matrix.size() ; i ++)
        {
            vector<int> sum(matrix[0].size() , 0);
            for (int j = i ; j < matrix.size() ; j ++)
            {
                for (int k = 0 ; k < matrix[0].size() ; k ++)
                {
                    sum[k] += matrix[j][k];
                }
                ans += getsubarraysum(sum , target);
            }
        }
        
        return ans;
    }
};