#include <vector>
#include <iostream>
using namespace std;









int majorityElement(vector<int>& nums) {
    int i = 0 , count = 0;
    for (int &x : nums) {
        if (count == 0) i = x;
        if (i == x) count ++;    
        else count --;
    }
    return i;
}

int main() {
    vector<int> x{2,2,1,1,1,2,2};
    cout << majorityElement(x);
}