#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;








string decodeString(string s) {
	string num = "" , temp = "";
	stack<int> Stack;
	stack<string> Stack_str;
	Stack.push(1);
	Stack_str.push("");
	for (char x : s) {
		if ('0' <= x and x <= '9') {
			num += x;
		}
		else if (x == '[') {
			int repeat = atoi(num.c_str());
			num = "";
			Stack.push(repeat);
			Stack_str.push("");
		}
		else if (x == ']'){
			string temp = Stack_str.top();
			for (int i = 0;i < Stack.top() - 1; i++) temp += Stack_str.top();
			Stack.pop();
			Stack_str.pop();
			Stack_str.top() += temp;
		}
		else {
			Stack_str.top() += x;
		}
	}
	return Stack_str.top();
}


int main() {
	string x = "";
	cin >> x;
	cout << decodeString(x);
}