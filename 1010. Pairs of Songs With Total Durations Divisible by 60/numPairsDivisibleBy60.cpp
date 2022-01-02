#include <vector>
#include <iostream>
using namespace std;



int numPairsDivisibleBy60(vector<int>& time) {
    vector<int> Count_div(60 , 0);
    int ans = 0;
    for (int duration : time) Count_div[duration%60] += 1;
    for (int remainder = 1 ; remainder < 30 ; remainder ++) ans += Count_div[remainder] * Count_div[60 - remainder];
    ans += Count_div[0] * ( Count_div[0] - 1 ) / 2 ; 
    ans += Count_div[30] * ( Count_div[30] - 1 ) / 2 ;
    return ans;
}


int main(){
    vector<int> time({30,20,150,100,40});
    cout << numPairsDivisibleBy60(time);
}