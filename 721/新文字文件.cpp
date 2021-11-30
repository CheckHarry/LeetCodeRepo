#include <set>
#include <map>
#include <vector>
#include <string>
#include <array>
#include <iostream>
using namespace std;




vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
	int smallest_num = 0;
	array<string, 1010> array_user({ "" });
	map<string, int> mail_mapping;
	vector<vector<string>> ans;
	for (vector<string> user_info : accounts) {
		bool is_user_already_exist = false;
		int userno = 0;
		for (int i = 1; i < user_info.size(); i++) {
			if (mail_mapping.find(user_info.at(i)) != mail_mapping.end()) {
				is_user_already_exist = true;
				userno = mail_mapping[user_info.at(i)];
			}
		}
		if (is_user_already_exist){
			for (int i = 1; i < user_info.size(); i++) mail_mapping.insert(pair<string, int>(user_info.at(i), userno));
		}
		else {
			smallest_num++;
			for (int i = 1; i < user_info.size(); i++) mail_mapping.insert(pair<string, int>(user_info.at(i), smallest_num));
			array_user[smallest_num] = user_info.at(0);
		}
	}
	for (int i = 1; i <= smallest_num; i++) {
		ans.push_back(vector<string>({ array_user.at(i) }));
	}
	map<string, int>::iterator it = mail_mapping.begin();
	for (; it != mail_mapping.end(); it++) {
		ans[it->second - 1].push_back(it->first);
	}
	return ans;
}


int main() {
	vector<vector<string>> x({ {"John", "johnsmith@mail.com", "john_newyork@mail.com"},{"John", "johnsmith@mail.com", "john00@mail.com"},{"Mary", "mary@mail.com"},{"John", "johnnybravo@mail.com"} });
	vector<vector<string>> ans = accountsMerge(x);
	for (vector<string> user : ans) {
		for (string userinfo : user) cout << userinfo << ' ';
		cout << endl;
	}
	
}