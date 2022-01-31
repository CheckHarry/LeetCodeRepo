#include <vector>
using namespace std;





int maximumWealth(vector<vector<int>>& accounts) {
    int ans = 0;
    for (vector<int>&x : accounts){
        int temp = 0;
        for (int w : x) temp += w;
        ans = max(ans , temp);
    }
    return ans;
}