#include <vector>
using namespace std;


int maxProfit(vector<int>& prices) {
    int ans = 0 , k = 0 ;
    for (int i = 1 ; i < prices.size(); i ++){
        if (k > 0) k = k + prices[i] - prices[i-1];
        else k = prices[i] - prices[i-1];
        ans = max(k , ans);
    }
    return ans;
}