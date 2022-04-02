#include <vector>
using namespace std;





int splitArray(vector<int> &nums, int m)
{   
    int l = 0 , r = 0;
    for (int num : nums){
        l = max(l , num);
        r += num;
    }
    while (l < r){
        int mid = (l + r) / 2 , sum = 0 , count = 0;
        for (int num : nums){
            if (sum + num > mid){
                count ++;
                sum = num;
            }
            else{
                sum += num;
            }
        }
        count ++;
        if (count > m)
            l = mid + 1;
        else 
            r = mid;
    }
    return l;
}