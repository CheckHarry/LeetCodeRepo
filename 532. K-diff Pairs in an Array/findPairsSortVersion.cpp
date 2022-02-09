#include <vector>
#include <algorithm>
using namespace std;


int findPairs(vector<int>& nums, int k) {
    sort(nums.begin() , nums.end());
    int left = 0 , right = 1 , ans = 0;
    while(right < nums.size()){
        if (nums[right] - nums[left] < k) right ++;
        else if(nums[right] - nums[left] > k) left ++;
        else if (left != right && (nums[right - 1] != nums[right] || left != right)){
            ans ++;
            right ++;
        }
    }
    return ans;
}