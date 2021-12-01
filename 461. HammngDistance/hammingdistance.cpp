#include <math.h>
using namespace std;







int count1s(int x) {
	int count = 0;
	while (x != 0) {
		count++;
		x = (x - 1) & x;
	}
	return count;
}


int hammingDistance(int x, int y) {
	return count1s((x|y)-(x&y));
}

