#include <vector>
#include <array>
using namespace std;


int jump(vector<int>& nums) {
	int cur = 0 , max_pos = 0 , left = 0 , right = 1;
	while (max_pos < nums.size() - 1) {
		max_pos = right;
		for (int i = left; i < right; i++) max_pos = max(max_pos, nums[i] + i); 
		cur++;
		left = right;
		right = max_pos + 1;
	}
	return cur;
}

int main() {
	vector<int> nums({ 2,3,1,1,4 });
	printf("%d", jump(nums));
}