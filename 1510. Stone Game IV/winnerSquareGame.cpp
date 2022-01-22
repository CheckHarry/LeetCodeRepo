#include <vector>
#include <iostream>
using namespace std;




bool winnerSquareGame(int n) {
    vector<bool> NP(n + 1 , false);
    for (int i = 1 ; i * i <= n; i ++) NP[i * i] = true;
    for (int i = 1 ; i <= n ; i ++){
        if (NP[i]) continue;
        for (int j = 1 ;i + j*j <= n; j ++) NP[i + j*j] = true;
    }
    return NP[n];
}


 
int main(){
    winnerSquareGame(20);
}