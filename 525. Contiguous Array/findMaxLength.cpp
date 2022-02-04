#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;



int findMaxLength(vector<int>& nums) {
    unordered_map<int , int> map;
    int ans = 0 , count = 0;
    map[0] = -1;
    for (int i = 0 ; i < nums.size() ; i ++){
        if (nums[i] == 0) count --;
        else count ++;
        if (map.find(count) != map.end()) ans = max(ans , i - map[count]);
        else map[count] = i;
    }
    return ans;
}


int main(){
    vector<int> x{0,0,0,0,0,1,1,1,1,1};
    cout << findMaxLength(x);
}