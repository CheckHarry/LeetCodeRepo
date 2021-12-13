#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string, int> key_mapping;
	vector<vector<string>> bags_string;
	for (string s : strs) {
		string temp = s;
		sort(temp.begin(), temp.end());
		if (key_mapping.find(temp) == key_mapping.end()) {
			bags_string.push_back(vector<string>({ s }));
			key_mapping.insert(pair <string, int>(temp , bags_string.size() - 1));
		}
		else {
			vector<string> &set_to_insert = bags_string[key_mapping.find(temp)->second];
			(set_to_insert).push_back(s);
		}
	}
	return bags_string;
}


int main() {
	vector<string> A({"eat", "tea", "tan", "ate", "nat", "bat"});
	vector<vector<string>> x = groupAnagrams(A);
}