#include <vector>
#include <algorithm>
using namespace std;





vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
	sort(arr.begin(), arr.end());
	vector<vector<int>> to_return;
	int cur = 100010;
	for (int n = 0; n < arr.size() - 1; n++) {
		if ((arr[n + 1] - arr[n]) < cur) {
			to_return = vector<vector<int>>();
			to_return.push_back(vector<int>({ arr[n] , arr[n + 1] }));
			cur = arr[n + 1] - arr[n];
		}
		else if ((arr[n + 1] - arr[n]) == cur) to_return.push_back(vector<int>({ arr[n] , arr[n + 1] })); 
	}
	return to_return;
}





int main() {
	vector<int> A({ 3,8,-10,23,19,-4,-14,27 });
	vector<vector<int>> x = minimumAbsDifference(A);
}