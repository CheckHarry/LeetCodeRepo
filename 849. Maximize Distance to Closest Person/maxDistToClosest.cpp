#include <vector>
#include <iostream>
using namespace std;






int maxDistToClosest(vector<int>& seats) {
    int cur_dist = 0 , cur_max_dist = 0 ;
    bool begin = true;
    for (int x : seats){
        if (x == 0) cur_dist ++;
        else{
            if(begin) begin = false;
            else cur_dist = cur_dist % 2 == 0 ? cur_dist / 2 : cur_dist / 2 +1;
            cur_max_dist = max(cur_dist , cur_max_dist);
            cur_dist = 0;
        }
    }
    cur_max_dist = max(cur_dist, cur_max_dist);
    return cur_max_dist;
}



int main(){
    vector<int> x{1,0,0,0,1,0,1};
    cout << maxDistToClosest(x);
}