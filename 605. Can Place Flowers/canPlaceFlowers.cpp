#include <vector>
#include <iostream>
using namespace std;




bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n == 0) return true;
    if (flowerbed.size() == 1) {
        if (flowerbed[0] == 0) return 1 >= n;
        else return false;
    }
    int m = 0;
    if (flowerbed[1] == 0) {
        flowerbed[0] = 1;
        m ++;
    }
    for (int i = 1 ; i < flowerbed.size() - 1;){
        if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0){
            flowerbed[i] = 1;
            m ++;
            i += 2;
        }
        else i ++;
    }
    if (flowerbed[flowerbed.size() - 2] == 0) m ++;
    return m >= n;
}

int main(){
    vector<int> x{1,0,0,0,1};
    cout << canPlaceFlowers(x , 1);
}