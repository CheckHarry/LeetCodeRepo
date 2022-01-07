#include <vector>
#include <iostream>
using namespace std;

int searchInsert(vector<int>& nums, int target){
	int left = 0 , right = nums.size() - 1;
	while(true){
		if (right - left <= 1) break;
		if(nums[(left + right) / 2] < target) left = (left + right) / 2;
		else if (nums[(left + right) / 2] > target) right = (left + right) / 2;
		else break;
	}
	if (right - left <= 1) {	
		if (target < nums[left]) return 0;
		else if(nums[left] == target) return left;
		else if(target <= nums[right]) return left + 1;
		else return right + 1;
	}
	else return (left + right) / 2;
}

int main(){
	vector<int> x{1,3,4,5};
	searchInsert(x , 2);
}