#include <vector>
using namespace std;










int uniquePaths(int m, int n) {
    long long ans = 1 , c = n  , r = 1;
    while(c <= m + n - 2){
        ans = (ans * c) / r;
        c ++ ;
        r ++ ;
    }
    return ans;
}