#include <vector>
#include <algorithm>
using namespace std;






bool nextPermute(vector<int>& nums , int size , int len) {
	if (len == 1) return false;
	else {
		bool is_change = nextPermute(nums, size, len - 1);
		if (is_change) return true;
		else if (nums[size - len] < nums[size - len + 1]){
			for (int index = size - len + 1; index < size + 1; index++) 
				if (index == size || nums[size - len] >= nums[index]) {
					int temp = nums[index - 1];
					nums[index - 1]  = nums[size - len];
					nums[size - len] = temp;
					sort(nums.begin() + size - len + 1 , nums.end());
					break;
				}
			return true;
		}
		else return false;
		}
	}



void nextPermutation(vector<int>& nums) {
	if (!nextPermute(nums, nums.size(), nums.size()))
		sort(nums.begin(), nums.end());
}
