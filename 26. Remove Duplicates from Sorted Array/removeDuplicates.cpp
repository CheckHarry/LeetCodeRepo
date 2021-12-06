#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int cur_pos = 0, cur_num = -101;
    for (int x : nums) {
        if (x > cur_num) {
            nums[cur_pos] = x;
            cur_pos++;
            cur_num = x;
        }
    }
    return cur_pos ;
}



