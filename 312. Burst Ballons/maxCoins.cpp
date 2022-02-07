#include <vector>
#include <iostream>
using namespace std;



int maxCoins(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    vector<vector<int>> dp(nums.size() , vector<int>(nums.size() , 0));
    for (int i = 0 ; i < nums.size() ; i ++) {
        if (i == 0) dp[i][i] = nums[i] * nums[i + 1];
        else if(i == nums.size() - 1) dp[i][i] = nums[i - 1] * nums[i];
        else dp[i][i] = nums[i - 1] * nums[i] * nums[i + 1];
    }
    for (int i = 1 ; i < nums.size() ; i ++){
        for (int j = 0 ; j < nums.size() ; j ++){
            if (j + i >= nums.size()) break;
            for (int k = j ; k <= j + i ; k ++){
                int last_score = nums[k] , left = 1 , right = 1;
                if (j != 0) left = nums[j - 1];
                if (j + i != nums.size() - 1) right = nums[j + i + 1];
                last_score = left * last_score * right;
                if (k == 0) dp[j][j + i] = max(dp[j][j + i] , last_score + dp[k + 1][j + i]);
                else if(k == nums.size() - 1) dp[j][j + i] = max(dp[j][j + i] , dp[j][k - 1] + last_score);
                else dp[j][j+i] = max(dp[j][j + i] , dp[j][k - 1] + last_score  + dp[k + 1][j + i]);
            }
        }
    }
    return dp[0][nums.size() - 1];
}

int main(){
    vector<int> x{1,5,4,7,7,8,9,7,8,5,8,6,2,4,1,8,5,8,6,2,4,1,3,8,5,8,6,2,4,1,3,8,5,8,6,2,4,1,3,8,5,8,6,2,4,1,33,0,7,9};
    cout << maxCoins(x);
}