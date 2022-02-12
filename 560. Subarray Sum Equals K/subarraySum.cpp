#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;



int subarraySum(vector<int>& nums, int k) {
    unordered_map<int , int> map;
    int sum = 0 , ans = 0;
    map[0] = 1;
    for (int i = 0 ; i < nums.size() ; i ++){
        sum += nums[i];
        ans += map[sum - k];
        map[sum] ++;
    }        
    return ans;
}

int main(){
    vector<int> x{1,1,1};
    cout << subarraySum(x , 3);
}