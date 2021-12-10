#include <vector>
#include <iostream>
using namespace std;


struct invalid {
	int left = 0;
	int middle = 0;
	int right = 0;
};


void dfs(invalid pos, int stage, int size, int &total) {
	if (stage == size - 1) {
		int invalid_pos = pos.left | pos.middle | pos.right;
		for (int i = 1; i <= size; i++) if ((invalid_pos | 1 << i) != invalid_pos) total++;
	}
	else {
		int invalid_pos = pos.left | pos.middle | pos.right;
		for (int i = 1; i <= size; i++) {
			if ((invalid_pos | 1 << i) != invalid_pos) {
				invalid temp = pos;
				temp.left = (temp.left | 1 << i) << 1;
				temp.right = (temp.right | 1 << i) >> 1;
				temp.middle = temp.middle | 1 << i;
				dfs(temp, stage + 1, size, total);
			}
		}
	}

}

int totalNQueens(int n) {
	int total = 0;
	invalid pos;
	dfs(pos, 0, n , total);
	return total;
}


int main() {
	cout << totalNQueens(13);

}