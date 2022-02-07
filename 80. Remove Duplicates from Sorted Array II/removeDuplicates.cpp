#include <vector>
#include <iostream>
using namespace std;


int removeDuplicates(vector<int>& nums) {
    int cur = -1 , count = 0 , left = 0 , right = 0 , size = nums.size();
    for (int i = 0 ; i < nums.size() ; i ++){
        if(cur == nums[i]){
            count ++;
            if (count > 2) {
                nums[i] = -10001;
                size --;
            }
        }
        else {
            cur = nums[i] ;
            count = 1;
        }
    }
    while(true){
        while(left < nums.size() && nums[left] >= -10000) left ++;
        right = left ;
        while(right < nums.size() && nums[right] < -10000) right ++;
        if (left >= nums.size() || right >= nums.size()) break;
        nums[left] = nums[right];
        nums[right] = -10001;
    }
    return size;
}

int main(){
    vector<int> x{1,1,1,2,2,2,2,3,3,3,3};
    removeDuplicates(x);
}