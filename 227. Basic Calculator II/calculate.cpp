#include <string>
#include <iostream>
using namespace std;




int calculate_recursive(int offset, string& s, bool positive) {
	if (offset >= s.size()) return 0;
	int  temp = 1, cur_offset = offset, cur = 0;
	char prev_sym = '*';
	bool is_positive = true;
	for (; cur_offset < s.size(); cur_offset++) {
		if (s[cur_offset] == ' ') continue;
		if ('0' <= s[cur_offset] and s[cur_offset] <= '9') {
			int x = s[cur_offset] - '0';
			cur = cur * 10 + x;
		}
		else if (s[cur_offset] == '+') break;
		else if (s[cur_offset] == '-') {
			is_positive = false;
			break;
		}
		else {
			if (prev_sym == '*') temp *= cur;
			else temp /= cur;
			prev_sym = s[cur_offset];
			cur = 0;
		}
	}
	if (prev_sym == '*') temp *= cur;
	else temp /= cur;
	return (positive ? 1 : -1) * temp + calculate_recursive(cur_offset + 1, s, is_positive);
}


int calculate(string s) {
	return calculate_recursive(0, s, true);
}


int main() {
	string x = "32/2/2/2";
	cout << calculate(x);
}