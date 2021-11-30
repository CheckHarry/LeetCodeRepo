#include <vector>
#include <string>
#include <array>
#include <set>
#include <map>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;





map<int , set<int>> mailedge;
map<string , int> mailmap;
array<string, 10010> mailno;
array<string, 10010> userno;
array<bool, 10010> used = { 0 };
int currentno = 0;


vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
	for (vector<string> account : accounts) {
		string current_account = account[1];
		for (int mailindex = 1; mailindex < account.size() ;  mailindex++) {
			if (mailmap.find(account[mailindex]) == mailmap.end()) {
				// register mail
				mailmap.insert(pair<string, int>(account[mailindex], currentno));
				mailno[currentno] = account[mailindex];
				userno[currentno] = account[0];
				mailedge.insert(pair<int, set<int>>(currentno, set<int>({})));
				currentno++;
				}
				if (account[mailindex] != current_account) {
					mailedge[mailmap[current_account]].insert(mailmap[account[mailindex]]);
					mailedge[mailmap[account[mailindex]]].insert(mailmap[current_account]);
					current_account = account[mailindex];
				}
		}
	}
	vector<vector<string>> ans;
	for (int index = 0; index < currentno; index++) {
		if (!used[index]) {
			vector<string> user({userno[index]});
			stack<int> nodes;
			nodes.push(index);
			used[index] = 1;
			set<int>::iterator it;
			while (true) {
				int mail = nodes.top();
				user.push_back(mailno[mail]);
				nodes.pop();
				for (it = mailedge[mail].begin(); it != mailedge[mail].end(); it++) {
					if (!used[*it]) {
						nodes.push(*it);
						used[*it] = true;
					}
				}
				if (nodes.empty()) break;
			}
			ans.push_back(user);
		}
		
		
	}
	
	return ans;
};

int main() {
	vector < vector < string >> x({ {"David","David0@m.co","David1@m.co"},{"David","David3@m.co","David4@m.co"},{"David","David4@m.co","David5@m.co"},{"David","David2@m.co","David3@m.co"},{"David","David1@m.co","David2@m.co"} });
	vector < vector < string >> k = accountsMerge(x);
	
	for (vector<string> user : k) {
		for (string data : user) {
			cout << data << endl;
		}
		cout << endl;
	}
}