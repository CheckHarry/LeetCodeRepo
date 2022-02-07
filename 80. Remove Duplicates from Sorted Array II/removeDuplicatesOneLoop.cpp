#include <vector>
#include <iostream>
using namespace std;


int removeDuplicates(vector<int>& nums) {
    int cur = -1  , countcur = 0 , left = 0 , right = 0 ,  count = 0;
    while(right < nums.size()){
        countcur =  cur == nums[right] ? ++ countcur : 1;
        if (cur == nums[right] && countcur  >= 3) {
            count ++;
            nums[right] = -10001;
        }
        else{
            cur = nums[right];
            if (count > 0 && !(cur == nums[right] && countcur  >= 3)){
                while(nums[left] != -10001 && left < right - 1) left ++;
                nums[left] = cur;
                nums[right] = -10001;
            }
        }
        right ++;
    }
    return nums.size() - count;
}

int main(){
    vector<int> x{1,1,1,2,2,2,2,3,3,3,3};
    cout << removeDuplicates(x);

}