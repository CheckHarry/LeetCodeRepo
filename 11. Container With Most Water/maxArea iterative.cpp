#include <vector>
#include <math.h>
#include <iostream>
using namespace std;




int maxArea(vector<int>& height) {
	int left = 0, right = height.size() - 1 , max_h = 0;
	while (true) {
		if (height[left] > height[right]) {
			max_h = max((right - left) * (height[left] - height[right]) , max_h);
			if (right - left == 1) break;
			right--;
		}
		else {
			max_h = max((right - left) * (height[right] - height[left]), max_h);
			if (right - left == 1) break;
			left++;
		}
	}

	return max_h;
}


int main() {
	vector<int> x({ 1,8,6,2,5,4,8,3,7 });
	cout << maxArea(x);
}