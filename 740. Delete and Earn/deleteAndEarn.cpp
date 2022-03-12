#include <vector>
using namespace std;






int deleteAndEarn(vector<int>& nums) {
    int ans = 0 , is_last = 1 , Max_ele = -1;
    for (int i : nums) Max_ele = max(Max_ele , i);
    vector<int> count(Max_ele + 2, 0);
    for (int i : nums) count[i] ++;
    int first = count[1] , second = max(count[1] , count[2] * 2);
    for (int i = 3 ; i <= Max_ele ; i ++){
        int temp = second;
        second = max(first + count[i] * i , second);
        first = temp;
    }
    return second;
}