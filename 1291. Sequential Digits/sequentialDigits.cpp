#include <vector>
#include <iostream>
using namespace std;


vector<int> sequentialDigits(int low, int high) {
    vector<int> to_return;
    for (int i = 1 ; i <= 9 ; i ++){
        for (int j = 1 ; j <=  10 - i; j ++){
            int to_push = j ;
            for (int k = 1 ; k < i ; k ++)to_push = to_push * 10 + (j + k);
            if (low <= to_push && to_push <= high) to_return.push_back(to_push);
        }
    }
    return to_return;
}

int main(){
    vector<int> x = sequentialDigits(10,300);
    for (int y : x) cout << y << ',';
}