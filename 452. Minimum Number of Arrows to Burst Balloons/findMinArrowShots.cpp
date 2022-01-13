#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) return 0;
    int ans = 1;
    auto compar = [](vector<int> &x , vector<int> &y){return x[1] < y[1];};
    sort(points.begin() , points.end() , compar);
    int pos = points[0][1];
    for (vector<int> &I : points){
        if (pos < I[0]){
            pos = I[1];
            ans ++;
        }
    }
    return ans;
}


int main(){
    vector<vector<int>> x{{1,2},{2,3},{3,4},{4,5}, {2,4}};
    cout<< findMinArrowShots(x);
}