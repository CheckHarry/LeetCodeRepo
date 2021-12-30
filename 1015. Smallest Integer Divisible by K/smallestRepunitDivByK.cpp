#include <vector>
using namespace std;





int smallestRepunitDivByK(int k) {
    if (k == 1) return 1;
    vector<bool> cycle(k , false);
    int to_return = 1 , cur = 1;
    while (cycle[cur] == false){
        cycle[cur] = true;
        to_return ++;
        cur = (cur * 10 + 1)%k;
        if (cur == 0) break;
    }
    if (cur == 0) return to_return;
    else return -1;
}
