#include <vector>
#include <math.h>
#include <iostream>
using namespace std;


inline int cal_h(vector<int>& piles , int k){
    int to_return = 0;
    for (auto&& i : piles) {
        if (i % k == 0) to_return += i / k;
        else to_return += i / k + 1;
    }
 
    return to_return; 
}

int minEatingSpeed(vector<int>& piles, int h) {
    int left = INT_MAX , right = 0 ;
    for (auto&& i : piles){
        left = min(i , left);
        right = max(i , right);
    }
    while (true)
    {
        if (right - left <= 1) break;
        if (cal_h(piles , (left + right) / 2) > h) left = (left + right) / 2;
        else{
            if (cal_h(piles , (left + right) / 2 - 1) > h ) return (left + right) / 2;
            else right = (left + right) / 2;
        }
    }
    if (cal_h(piles , left) <= h) return left;
    else return right;
    
}


int main(){
    vector<int> x{30,11,23,4,20};
    cout << minEatingSpeed(x , 5);
}