#include <vector>
#include <iostream>
using namespace std;


struct invalid {
	int left = 0;
	int middle = 0;
	int right = 0;
};


void dfs(invalid pos,  int stage , int size , vector<string>&board , vector<vector<string>>& boards) {
	if (stage == size - 1) {
		int invalid_pos = pos.left | pos.middle | pos.right;
		for (int i = 1; i <= size; i++) {
			if ((invalid_pos | 1 << i) != invalid_pos) {
				board[stage][i - 1] = 'Q';
				boards.push_back(board);
				board[stage][i - 1] = '.';
			}
		}
	}
	else {
		int invalid_pos = pos.left | pos.middle | pos.right;
		for (int i = 1; i <= size; i++) {
			if ((invalid_pos | 1 << i) != invalid_pos) {
				board[stage][i - 1] = 'Q';
				invalid temp = pos;
				temp.left = (temp.left | 1 << i) << 1;
				temp.right = (temp.right | 1 << i ) >> 1;
				temp.middle = temp.middle | 1 << i;
				dfs(temp, stage + 1, size , board, boards);
				board[stage][i - 1] = '.';
			}
		}
	}

}

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> boards;
	vector<string> board;
	invalid pos;
	for (int i = 0; i < n; i++) {
		string temp = "";
		for (int j = 0; j < n; j++) temp += '.';
		board.push_back(temp);
	}
	dfs(pos, 0, n, board, boards);
	return boards;
}


int main() {
	cout << solveNQueens(9).size();
		
}