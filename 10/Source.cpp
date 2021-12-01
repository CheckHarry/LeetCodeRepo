#include <string>
#include <vector>
#include <set>
#include <map>
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
struct state {
	map<int, set<int>> transistion; // represent char as int , as -1 represent epsilon (empty)
};

vector<state> toMachine(vector<lexeme> lexs) {
	vector<state> to_return;
	state start;
	int cur_index = 0;
	to_return.push_back(start);
	for (lexeme lex : lexs) {
		if (lex.type == 1) {
			to_return[cur_index].transistion.insert(pair<int, set<int>>(-1, { cur_index + 1 }));
			cur_index += 1;
			state to_insert1;
			to_return.push_back(to_insert1);
			to_return[cur_index].transistion.insert(pair<int, set<int>>(-1, { cur_index , cur_index + 1}));
			to_return[cur_index].transistion.insert(pair<int, set<int>>(lex.chr, { cur_index }));
			cur_index += 1;
			state to_insert2;
			to_return.push_back(to_insert2);
		}
		else {
			to_return[cur_index].transistion.insert(pair<int, set<int>>(lex.chr, { cur_index + 1 }));
			cur_index += 1;
			state to_insert;
			to_return.push_back(to_insert);
		}
	}
	return to_return;
}

set<int> epsilon_closure(set<int> &state_set, vector<state>& state_vec, char chr) {
	set<int>::iterator it;
	set<int> to_return;
	for (it = state_set.begin(); it != state_set.end(); it++) {
		if (state_vec[*it].transistion.find(chr) != state_vec[*it].transistion.end()) {
			to_return.insert(state_vec[*it].transistion[chr].begin(), state_vec[*it].transistion[chr].end());
		}
		if (state_vec[*it].transistion.find('.') != state_vec[*it].transistion.end()) {
			to_return.insert(state_vec[*it].transistion['.'].begin(), state_vec[*it].transistion['.'].end());
		}
	}
	int cursize = to_return.size();
	while (true) {
		for (it = to_return.begin(); it != to_return.end(); it++) {
			to_return.insert(state_vec[*it].transistion[-1].begin(), state_vec[*it].transistion[-1].end());
		}
		if (cursize == to_return.size()) break;
		cursize = to_return.size();
	}
	return to_return;
}

set<int> epsilon_closure(set<int>& state_set, vector<state>& state_vec) {
	set<int>::iterator it;
	set<int> to_return = state_set;
	int cursize = to_return.size();
	while (true) {
		for (it = to_return.begin(); it != to_return.end(); it++) {
			to_return.insert(state_vec[*it].transistion[-1].begin(), state_vec[*it].transistion[-1].end());
		}
		if (cursize == to_return.size()) break;
		cursize = to_return.size();
	}
	return to_return;
}


bool isMatch(string s, string p) {
	vector<state> state_vec = toMachine(parse(p));
	set<int> cur_state_set({ 0 });
	cur_state_set = epsilon_closure(cur_state_set , state_vec);
	for (string::iterator chr = s.begin(); chr != s.end(); chr ++ ) {
		cur_state_set = epsilon_closure(cur_state_set, state_vec, *chr);
	}
	if (cur_state_set.find(state_vec.size() - 1) != cur_state_set.end()) return true;
	else return false;
}

int main() {
	string p({ "a*b*aaa" });
	string s({ "bbbbbbbbbbbbbbbbbbbbbbbbbaaa" });
	cout << isMatch(s , p);
}