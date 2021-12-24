#include <vector>
#include <algorithm>
using namespace std;


bool compare(vector<int>& a, vector<int>& b) {
	return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	vector<vector<int>> to_return ;
	int left = -1, right = -1;
	sort(intervals.begin() , intervals.end() ,compare);
	for (vector<int> interval : intervals) {
		if (right < interval[0]) {
			to_return.push_back({ left , right });
			left = interval[0];
			right = interval[1];
		}
		else right = max(right , interval[1]);
	}
	to_return.erase(to_return.begin());
	to_return.push_back({ left , right });
	return to_return;
}



int main() {
	vector<vector<int>> a({ {5 , 6}, {1, 4}, { 4, 5 } });
	vector<vector<int>> b({ {1,4},{2,3} });
	merge(b);
}