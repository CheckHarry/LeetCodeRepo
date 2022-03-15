#include <stack>
#include <string>
#include <map>
#include <iostream>
using namespace std;

map<char, char> char_map = { {'(' , ')'} , {'{' , '}'} , {'[' , ']'}};


bool isValid(string str) {
	stack<char> to_push;
	for (char x : str) {
		if (x == '(' || x == '[' || x == '{') to_push.push(x);
		else {
			if (to_push.empty()) return false;
			if (char_map[to_push.top()] != x)
				return false;
			to_push.pop();
		}
	}
	if (to_push.empty()) return true;
	return false;
}


int main() {
	string x = "]";
	cout << isValid(x);
}