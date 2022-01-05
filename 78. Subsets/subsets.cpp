#include <vector>
#include <iostream>
using namespace std;



vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> to_return;
    int set = (1 << nums.size()) - 1;
    for(int subset = set; subset != 0; subset = set & (subset - 1)){
        vector<int> Subset_nums;
        int temp = subset , count = 0;
        for (;temp != 0 ; temp = temp >> 1) {
            if (temp % 2 == 1) Subset_nums.emplace_back(nums[count]);
            count ++;
        }
        to_return.emplace_back(Subset_nums);
    }
    to_return.push_back(vector<int>{});
    return to_return;
}


int main(){
    vector<int> x{1,2,3,7};
    vector<vector<int>> Subsets = subsets(x);
    for (vector<int> S : Subsets) {for(int x : S){cout<< x << ',';} cout << "END" << '\n';}
}