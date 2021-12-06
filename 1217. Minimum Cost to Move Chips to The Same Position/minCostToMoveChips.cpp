#include <vector>
using namespace std;









 int minCostToMoveChips(vector<int>& position) {
        int sum_odd = 0 , sum_even = 0;
        for (int x : position){
            if (x % 2 == 1) sum_odd ++;
            else sum_even ++ ;
        }
        return min(sum_odd , sum_even);
    }