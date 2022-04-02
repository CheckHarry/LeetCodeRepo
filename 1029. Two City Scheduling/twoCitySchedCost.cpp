#include <vector>
#include <algorithm>
using namespace std;




int twoCitySchedCost(vector<vector<int>>& costs) {
    vector<int> diff;
    int sum = 0;
    for (vector<int> &p : costs){
        diff.push_back(p[1] - p[0]);
        sum += p[0];
    }
    sort(diff.begin() , diff.end());
    for (int i = 0 ; i < costs.size()/2 ; i ++){
        sum += diff[i];
    }
    return sum;
}