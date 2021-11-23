#include <vector>
#include <unordered_map>
using namespace std;









vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> datamap;
	vector<int> result({ 0 , 0 });
	for (int index = 0; index < nums.size(); index ++) {
		if (datamap.find(target - nums[index]) != datamap.end()) {
			result[0] = index; result[1] = datamap[index];
		}
		else datamap[nums[index]] = index;
	}
	return result;
}



