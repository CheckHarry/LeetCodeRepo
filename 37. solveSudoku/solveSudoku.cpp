#include <vector>
#include <string>
#include <iostream>
using namespace std;

void move(int& x, int& y) {
	if (y == 8) {
		x = x + 1;
		y = 0;
	}
	else {
		x = x;
		y = y + 1;
	}
}


void next_pos(int &curpos_x , int &curpos_y , vector<vector<char>>& board) {
	int &x = curpos_x , &y = curpos_y;
	move(x, y);
	while (board[x][y] != '.') move(x, y);
}

vector<int> last_pos(vector<vector<char>>& board) {
	int x = 0, y = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == '.') {
				x = i;
				y = j;
			}
		}
	}
	return vector<int>({ x,y });
}

bool is_valid(int x, int y ,vector<vector<char>>& board ) {
	int num_used[10] = {0};
	for (int i = 0; i < 9; i++) {
		if (48 <= board[i][y] && board[i][y] <= 57) {
			num_used[board[i][y] - 48] += 1;
			if (num_used[board[i][y] - 48] == 2) return false;
		}
	}
	for (int i = 0; i < 10; i++) num_used[i] = 0;
	for (int i = 0; i < 9; i++) {
		if (48 <= board[x][i] && board[x][i] <= 57) {
			num_used[board[x][i] - 48] += 1;
			if (num_used[board[x][i] - 48] == 2) return false;
		}
	}
	for (int i = 0; i < 10; i++) num_used[i] = 0;
	int x_low = x / 3, y_low = y / 3;
	for (int i = x_low * 3; i < x_low * 3 + 3; i++) {
		for (int j = y_low * 3; j < y_low * 3 + 3; j++) {
			if (48 <= board[i][j] && board[i][j] <= 57) {
				num_used[board[i][j] - 48] += 1;
				if (num_used[board[i][j] - 48] == 2) return false;
			}
		}
	}
	return true;
}

bool dfs(int x, int y, vector<vector<char>>& board , vector<int> lastpos) {
	int pos_x = x, pos_y = y;
	if (pos_x == lastpos[0] && pos_y == lastpos[1]) {
		for (int i = 1; i <= 9; i++) {
			board[pos_x][pos_y] = i + 48;
			if (is_valid(pos_x, pos_y, board)) return true;
		}
		return false;
	}
	else {
		next_pos(pos_x,pos_y,board);
		for (int i = 1; i <= 9; i++) {
			board[pos_x][pos_y] = i + 48;
			if (is_valid(pos_x, pos_y, board)) { 
				if (dfs(pos_x, pos_y, board, lastpos) ) {
					return true;
				}
			};
		}
		board[pos_x][pos_y] = '.';
		return false;
	}

}

void solveSudoku(vector<vector<char>>& board) {
	int x = 0, y = -1;
	dfs(x, y, board, last_pos(board));
}

int main() {
	vector<vector<char>> board({ {'.','7','.','.','6','4','5','.','1'},{'.','.','.','.','.','8','3','.','9'},{'.','6','8','3','5','.','.','.','.'},{'8','2','.','.','.','.','1','3','.'},{'.','.','6','.','.','.','9','.','.'},{'.','9','5','.','.','.','.','7','2'},{'.','.','.','.','3','9','2','5','.'},{'2','.','9','4','.','.','.','.','.'},{'4','.','3','5','7','.','.','9','.'} });
	solveSudoku(board);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << ',';
		}
		cout << '\n';
	}
}