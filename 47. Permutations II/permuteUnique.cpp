#include <vector>
#include <unordered_set>
using namespace std;



int convert(vector<int> &x)
    {
        int sum = 0;
        for (int c : x)
        {   
            sum = sum * 10 + c;
        }
        return sum;
    }
    
    
    void permute(vector<int> &x , vector<vector<int>> &v , unordered_set<int> &s , int l)
    {
        if (l == x.size() - 1)
        {
            if  (s.find(convert(x)) == s.end())
            {
                s.insert(convert(x));
                v.push_back(x);
            }
            return;
        }
        
        for (int i = l ; i < x.size() ; i ++)
        {
            swap(x[l] , x[i]);
            permute(x , v , s , l + 1);
            swap(x[l] , x[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> to_return ;
        unordered_set<int> s;
        permute(nums , to_return , s , 0);
        return to_return;
    }