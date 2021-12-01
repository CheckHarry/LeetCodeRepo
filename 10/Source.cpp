#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;


struct lexeme {
	int  type; // 0 represent non-repeat , 1 represent repeat
	char chr;
};



vector<lexeme> parse(string& str) {
	char cur = str[0];
	vector<lexeme> to_return;
	for (char x : str.substr(1) + ' ') { // add padding to handle the last word.
		if (cur == '*') { 
			cur = x;
			continue;
		}
		lexeme new_lexeme;
		new_lexeme.type = (x == '*') ? 1 : 0;
		new_lexeme.chr = cur;
		to_return.push_back(new_lexeme);
		cur = x;
	}
	return to_return;
}

// turning the lexem vector to NFA. then simulate the NFA using set.

// compute the next state(s) by passing current state and character;
set<int> next_states(int index, lexeme& lex, char chr , bool laststate) {
	set<int> to_return;
	if (!laststate){
	if (lex.type == 1) {
		if (lex.chr == '.') to_return.insert({ index , index + 1 });
		else if (lex.chr == chr) to_return.insert({ index , index + 1 });
		else  to_return.insert({ index + 1 });
	}
	else {
		if (lex.chr == '.') to_return.insert(index + 1);
		else if (lex.chr == chr) to_return.insert(index + 1);
	}
	}
	else {
		if (lex.type == 1) {
			if (lex.chr == '.') to_return.insert({index});
			else if (lex.chr == chr) to_return.insert({index});
			else  to_return.insert({ index });
		}
	}
	return to_return;
}

bool isMatch(string s, string p) {
	vector<lexeme> lexs = parse(p);
	int laststate = lexs.size() - 1 , acceptstate = lexs.size();
	set<int> cur_state_set({ 0 });
	for (string::iterator chr = s.begin(); chr != s.end(); chr ++ ) {
		set<int> next_state_set;
		set<int>::iterator it;
		for (it = cur_state_set.begin(); it != cur_state_set.end(); it++) {
			set<int> temp;
			temp = (chr != s.end() - 1) ? next_states(*it, lexs[*it], *chr , *it == laststate) : next_states(*it, lexs[*it], *chr, *it == false);
			next_state_set.insert(temp.begin(), temp.end());
		}
		cur_state_set = next_state_set;
		if (cur_state_set.empty()) return false;
	}

	return cur_state_set.find(acceptstate) != cur_state_set.end();
}

int main() {
	string p({ "ab*ba.*kasdc*" });
	string s({ "abbattasdtkasdcccccc" });
	cout << isMatch(s,p);
}