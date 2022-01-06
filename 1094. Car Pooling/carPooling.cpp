#include <vector>
#include <iostream>
using namespace std;




bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> Count(1001 , 0);
    int Max_location = 0 , sum = 0;
    for (vector<int> trip : trips) {
        Count[trip[1]] += trip[0];
	    Count[trip[2]] -= trip[0];
        Max_location = max(trip[2] , Max_location);
    }
    for (int i = 0 ; i < Max_location ; i ++){
        sum += Count[i];
        if (sum > capacity) return false;
    }
    return true;
}


int main(){
    vector<vector<int>> trips{{2,1,5},{3,3,7}};
    cout << carPooling(trips , 4);
}
