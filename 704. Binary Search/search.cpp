#include <vector>
using namespace std;






int search(vector<int>& nums, int target) {
    int left = 0 , right = nums.size() - 1;
    while (right - left > 1){
        int mid = (left + right) / 2;
        if (nums[(left + right) / 2] < target) left = mid + 1;
        else {
            if (nums[(left + right) / 2] == target) return (left + right) / 2;
            right = mid - 1;
        }
    }
    if (nums[left] == target) return left;
    else if (nums[right] == target) return right;
    else return -1;
}