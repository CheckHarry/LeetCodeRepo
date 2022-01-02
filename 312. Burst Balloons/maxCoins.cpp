#include <vector>
#include <iostream>
using namespace std;




int dfs(vector<bool>& mask , vector<int>& nums , int pos , int step){
    if (step == nums.size()) return nums[pos];
    else{
        int left = -1 , right = -1;
        mask[pos] = true;
        for(int i = pos - 1 ; i >= 0 ; i --) {if (mask[i] == false) left = i;}
        for(int i = pos + 1 ; i < nums.size() ; i ++) {if (mask[i] == false) right = i;}
        int left_max_ans = -1 , right_max_ans = -1;
        if (left  != -1) left_max_ans  = dfs( mask , nums , left  , step + 1 );
        if (right != -1) right_max_ans = dfs( mask , nums , right , step + 1 );
        mask[pos] = false;
        if(left != -1 and right != -1) return max(left_max_ans + nums[left] * nums[pos] * nums[right] , right_max_ans + nums[left] * nums[pos] * nums[right]);
        else if(left == -1) return right_max_ans +  nums[pos] * nums[right];
        else return left_max_ans + nums[pos] * nums[left];
    }
}

int maxCoins(vector<int>& nums) {
    vector<bool> mask( nums.size() , false);
    int Max = -1;
    /*
    for (int pos = 0 ; pos < nums.size() ; pos ++){
        mask[pos] = true;
        Max = max(Max , dfs(mask , nums , pos , 1));
        mask[pos] = false;
    }
    */
    mask[1] = true;
    return dfs(mask , nums , 1 ,1);
    return Max;
}

int main(){
    vector<int> nums{3,1,5,8};
    cout << maxCoins(nums);
}