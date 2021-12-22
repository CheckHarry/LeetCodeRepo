#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct node  {
	enum Type { repeat, normal, root };
	Type type;
	int parent;
	vector<int> child;
	string value;
	int repeat_time = 0;
};


vector<node> parse(string &s) {
	vector<node> to_return;
	node Root;
	Root.type = node::root;
	to_return.push_back(Root);
	int cur_parent = 0;
	string temp = "";
	for (int i = 0; i < s.size(); i ++) {
		if (97 <= s[i] and s[i] <= 122) {
			node X;
			X.type = node::normal;
			X.value = s[i];
			X.parent = cur_parent;
			to_return.push_back(X);
			to_return[cur_parent].child.push_back(to_return.size()-1);
		}
		else if ('0' <= s[i] and s[i] <= '9') temp += s[i]; 
		else if (s[i] == '[') {
			node X;
			X.type = node::repeat;
			X.repeat_time = atoi(temp.c_str());
			X.parent = cur_parent;
			to_return.push_back(X);
			to_return[cur_parent].child.push_back(to_return.size() - 1);
			cur_parent = to_return.size() - 1;  
			temp = "";
		}
		else if (s[i] == ']') cur_parent = to_return[cur_parent].parent; 
	}
	return to_return;
}


string decodeString_tree(node& tree_root, vector<node>& tree) {
	string to_return = "";
	if (tree_root.type == node::normal) return tree_root.value;
	for (int children : tree_root.child) to_return += decodeString_tree(tree[children], tree); 
	string temp = to_return;
	if (tree_root.type == node::repeat) for (int i = 0; i < tree_root.repeat_time - 1; i++) to_return += temp; 
	return to_return;
}


string decodeString(string s) {
	vector<node> tree = parse(s);
	return decodeString_tree(tree[0], tree);
}



