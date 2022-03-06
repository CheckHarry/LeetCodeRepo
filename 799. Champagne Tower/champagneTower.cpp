#include <vector>
using namespace std;





double champagneTower(int poured, int query_row, int query_glass) {
    vector<double> dp(101 , 0);
    dp[0] = poured;
    for (int i = 1 ; i <= query_row ; i ++){
        for (int j = i - 1; j >= 0 ; j --){
           dp[j] = max((dp[j] - 1.0) / 2 , 0.0);
           dp[j+1] += dp[j];
        }
    }
    return min(dp[query_glass] , 1.0);
}