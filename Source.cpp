#include <vector>
#include <iostream>
using namespace std;
#define min(x , y) x > y ? y : x;
#define max(x , y) x > y ? x : y;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	return 1;
}

vector<int> findMedianSortedArrays_even(vector<int>& nums1, vector<int>& nums2) {
	int totalLength = nums1.size() + nums2.size();
	int i = nums1.size() / 2, j = totalLength / 2 - i; // length of left interval
	while (true) {
		if (!(nums1[i] >= nums2[j - 1]))  i += max((i / 2) , 1);
		else if (!(nums2[j] >= nums1[i - 1])) i -= max((i / 2) , 1);
		else break;
		i = min(nums1.size(), i);
		j = totalLength / 2 - i;
		cout << i << ',' << j << endl;
		if (i == 0 || j == 0) break;
	}
	return vector<int>({ i, j});
}

int main() {
	vector<int> x({1,2,3 , 9 ,25});
	vector<int> y({0, 4,4 , 7 , 21});
	for (int i : findMedianSortedArrays_even(x, y)) {
		cout << i << endl;
	}
}