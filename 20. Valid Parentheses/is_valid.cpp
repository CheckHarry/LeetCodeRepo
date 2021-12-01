#include <stack>
#include <string>
#include <map>
#include <iostream>
using namespace std;

map<char, char> char_map = { {'(' , ')'} , {'{' , '}'} , {'[' , ']'}};


bool is_valid(string str) {
	stack<char> to_push;
	char peek = '.';
	for (char x : str) {
		if (x == '(' or x == '[' or x == '{') {
			to_push.push(x);
		}
		else {
			peek = to_push.top();
			to_push.pop();
			if (char_map[peek] != x)
				return false;
		}
	}
	if (to_push.empty())
		return true;
	return false;
}


int main() {
	string x = "]";
	cout << is_valid(x);
}