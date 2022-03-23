#include <string>
using namespace std;




string getSmallestString(int n, int k) {
    int c = (k - n) / 25 , b = (k - n) % 25 == 0 ? 0 : 1;
    int a = n - b - c;
    return string(a , 'a') +  string(b , k - a - 26*c - 1 + 'a') + string(c , 'z');  
}