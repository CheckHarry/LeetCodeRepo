#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;



int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin() , intervals.end() , 
    [](vector<int>& x , vector<int>& y){return x[0] < y[0] || (x[0] == y[0] && x[1] > y[1]) ;});      
    int cur = 0 , count = 0;
    for (int i = 1 ; i < intervals.size() ; i ++){
        if (!(intervals[i][1] <= intervals[cur][1])){
            cur = i;
            count ++;
        }
    }
    return count + 1;
}


int main(){
    vector<vector<int>> x{
        {1 , 4},
        {1 , 3},
        {3 , 6},
        {2 , 8},
        {4 , 9},
        {5 , 10},
      
    };
    cout << removeCoveredIntervals(x);
}