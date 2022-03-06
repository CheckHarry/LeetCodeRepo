#include <vector>
using namespace std;







int numberOfArithmeticSlices(vector<int>& nums) {
    if (nums.size() < 3) return 0;
    int count = 2 , d = nums[1] - nums[0] , ans = 0;
    for (int i = 1 ; i < nums.size() - 1 ; i ++){
        if (d == nums[i + 1] - nums[i]) count ++;
        else{
            ans = ((count - 1) * (count - 2))/2;
            d = nums[i + 1] - nums[i];
            count = 2;
        }
    }
    ans += ((count - 1) * (count - 2))/2;
    return ans;
}







