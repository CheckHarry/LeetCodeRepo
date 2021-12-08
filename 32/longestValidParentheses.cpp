#include <string>
#include <stack>
using namespace std;





int longestValidParentheses(string s) {
	int cur_pos = s.size(), max_l = 0;
	stack<int> parentheses_stack;
	parentheses_stack.push(0);
	for (int i = 1; i < s.size(); i++) {
		if (!parentheses_stack.empty() and s.at(i) == ')' and s.at(parentheses_stack.top()) == '(') parentheses_stack.pop();
		else parentheses_stack.push(i);
	}
	while (!parentheses_stack.empty()) {
		max_l = max(cur_pos - parentheses_stack.top() - 1, max_l);
		cur_pos = parentheses_stack.top();
		parentheses_stack.pop();
	}
	max_l = max(cur_pos, max_l);
	return max_l;
}

