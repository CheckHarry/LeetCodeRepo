#include <string>
#include <iostream>
#include <math.h>
using namespace std;



string scan(string& str) {
	string to_retrun("");
	string::iterator it;
	int cur_state = 1;
	for (it = str.begin(); it != str.end(); it++) {
		switch (cur_state)
		{
		case 1:
			if (*it == ' ') {}
			else if (*it == '0' || *it == '+' || *it == '-') {
				cur_state = 3;
				if (*it == '+' || *it == '-') to_retrun += *it;
			}
			else if ((49 <= *it && *it <= 57)) {
				cur_state = 2;
				to_retrun += *it;
			}
			else {
				cur_state = 4;
			}
			continue;
		case 2:
			if (48 <= *it && *it <= 57) to_retrun += *it;
			else cur_state = 4;
			continue;
		case 3:
			if (*it == '0');
			else if ((49 <= *it && *it <= 57)) {
				cur_state = 2;
				to_retrun += *it;
			}
			else cur_state = 4;
			continue;
		default: break;
		}
	}

	return to_retrun;
}

int myAtoi(string s) {
	string processed = scan(s);
	if (processed.empty()) return 0;
	if (processed.size() == 1) {
		if (processed[0] == '+' || processed[0] == '-') return 0;
		else return processed[0] - 48;
	}
	string numstring = (processed[0] == '+' || processed[0] == '-') ? processed.substr(1) : processed;
	string max = processed[0] == '-' ? "2147483648" : "2147483647";
	int    max_int = processed[0] == '-' ? -2147483648 : 2147483647, d = 1, ans = 0, count = 0;

	if (numstring.size() > 10) return max_int;
	else if (numstring.size() == 10) {
		int digitno = 0;
		for (const char chr : numstring) {
			if (chr < max[digitno]) break;
			else if (chr > max[digitno]) return max_int;
			digitno++;
		}
		if (digitno == 10) return max_int;
	}
	for (string::iterator it = numstring.end() - 1; ; it--) {
		ans += (*it - 48) * d;
		if (count >= 9)break;
		d *= 10;
		count++;
		if (it == numstring.begin()) break;
	}
	return (processed[0] == '-' ? -1 : 1) * ans;
}




int main() {
	string x("-2147483648");
	cout << myAtoi(x);//2147483647
}