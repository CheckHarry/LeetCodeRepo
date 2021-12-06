#include <vector>
#include <math.h>
#include <iostream>
using namespace std;



int maxArea_index(vector<int>& height , int i , int j) {
	if ((j - i) == 1) return (min(height[i], height[j]));
	if (height[j] > height[i]) return max((j - i) * min(height[i], height[j]), maxArea_index(height, i + 1, j));
	else return max((j - i) * min(height[i], height[j]), maxArea_index(height, i , j - 1));
}


int maxArea(vector<int>& height) {
	return maxArea_index(height , 0, height.size() - 1);
}


