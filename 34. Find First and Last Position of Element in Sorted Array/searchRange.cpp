#include <vector>
#include <iostream>
using namespace std;

int find(vector<int> &nums , int target){
    int left = 0 , right = nums.size() - 1;
    while (true){
        if (right - left <= 1) break;
        if (nums[(left + right)/2] < target) left = (left + right) / 2;
        else if(nums[(left + right)/2] > target) right = (left + right) /2;
        else {
            if ((left + right) / 2 == 0 || nums[(left + right)/2 - 1] != target) break;
            right = (left + right) / 2;
        }
    }
    if (right - left <= 1){
        if (nums[left] == target) return left;
        else if(nums[right] == target) return right;
        else return -1;
    }
    return (left + right) / 2;
}


vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> to_return{-1 , -1};
    if (nums.size() == 0) return to_return;
    else{
        int ans_left ;
        int left , right = nums.size() - 1;
        ans_left = find(nums , target);
        if (ans_left == -1) return to_return;
        left = ans_left;
        while(true){
            if (right - left <= 1) break;
            if(nums[(left + right)/2] > target) right = (left + right) /2;
            else {
                if ((left + right) / 2 == nums.size() - 1 || nums[(left + right)/2 + 1] != target) break;
                left = (left + right) / 2;
            }
        }
        to_return[0] = ans_left ;
        if (right - left <= 1) to_return[1] = nums[right] == target ? right : left;
        else to_return[1] = (left + right)/2;
    }
    return to_return;
}



int main(){
    vector<int> x{5,7,7,8,8,10,13,13,13,13,13,19,19};
    vector<int> y = searchRange(x , 19);
    for (int i : y) cout << i << '\n';
}