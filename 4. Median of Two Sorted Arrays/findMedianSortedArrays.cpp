#include <vector>
#include <iostream>
using namespace std;

int in_range(int i, int size) {
	if (0 > i) return 0;
	else if (size < i) return size;
	else return i;
}


vector<int> findMedianSortedArrays_even(vector<int>& nums1, vector<int>& nums2) {
	int totalLength = (nums1.size() + nums2.size()) / 2; // assume nums1.size()  <= nums2.size()
	int i = 0, j = totalLength - i, step = nums1.size() / 2, leftmax, rightmin;// length of left interval
	while (true) {
		if (0 < j && nums1.size() > i && !(nums1[i] >= nums2[j - 1]))  i += step / 2 + 1;
		else if (0 < i && nums2.size() > j && !(nums2[j] >= nums1[i - 1])) i -= step / 2 + 1;
		else break;
		step = step / 2;
		i = in_range(i, nums1.size());
		j = totalLength - i;
	}
	if (i == nums1.size()) rightmin = nums2[j]; else if (j == nums2.size()) rightmin = nums1[i]; else rightmin = min(nums1[i], nums2[j]);
	if (i == 0) leftmax = nums2[j - 1]; else if (j == 0) leftmax = nums1[i - 1]; else leftmax = max(nums1[i - 1], nums2[j - 1]);
	return vector<int>({ leftmax , rightmin });
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	vector<int> temp;
	if (nums1.empty() or nums2.empty()) {
		vector<int>& nonzeronums = nums1.empty() ? nums2 : nums1;
		if (nonzeronums.size() % 2 == 0) return ((double)nonzeronums[nonzeronums.size() / 2] + (double)nonzeronums[nonzeronums.size() / 2 - 1]) / 2;
		else return nonzeronums[(nonzeronums.size() - 1) / 2];
	}
	int totallength = nums1.size() + nums2.size();
	if ((nums1.size() + nums2.size()) % 2 == 1) nums1.push_back(1000001);
	if (nums1.size() > nums2.size()) { temp = findMedianSortedArrays_even(nums2, nums1); }
	else { temp = findMedianSortedArrays_even(nums1, nums2); }
	if (totallength % 2 == 1) { return temp[0]; }
	else return ((double)temp[0] + (double)temp[1]) / 2;

}

