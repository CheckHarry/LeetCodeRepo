#include <vector>
using namespace std;












int singleNumber(vector<int>& nums) {
    int i = 0;
    for (int &x : nums) i ^= x;
    return i;
}