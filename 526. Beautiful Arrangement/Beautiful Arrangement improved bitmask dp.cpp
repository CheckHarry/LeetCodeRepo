#include <iostream>
#include <array>

using namespace std;


int count1s(int m) {
	int count = 0;
	while (m != 0) {
		m = (m - 1) & m;
		count++;
	}
	return count;
}

int countArrangement(int n) {
	array<int, 1 << 15> mask{0};
	for (int num = 1; num <= n; num++) mask[1 << (num - 1)] = 1; 
	for (int state = 1; state < 1 << n ; state++) 
		for (int ele = 1; ele <= n; ele++) 
			if ((1 << (ele - 1) | state) == state and (ele % count1s(state) == 0 or count1s(state) % ele == 0)) 
					mask[state] += mask[state - (1 << (ele - 1))];
	return mask[(1<<n) - 1];
}

int main() {
	cout << countArrangement(15) << endl;
}

