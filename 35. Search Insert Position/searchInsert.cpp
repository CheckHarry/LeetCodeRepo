#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target){
	int left = 0 , right = nums.size();
	while(true){
		if(nums[(left + right) / 2] < target);
		else if (nums[(left + right) / 2] > target);
		else break;
	}
	return (left + right) / 2;
}


