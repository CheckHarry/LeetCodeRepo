#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char , int>> st;
        string to_return = "";
        for (char c : s)
        {
            if (!st.empty() && c == st.back().first)
                st.back().second ++;
            else
                st.push_back({c , 1});
            
            if (st.back().second >= k)
            {
                st.back().second -= k;
                if (st.back().second == 0)
                    st.pop_back();
            }
        }
      
        for (auto&& p : st)
        {
            to_return += (string(p.second , p.first));
        }
        
        return to_return;
            
    }
};