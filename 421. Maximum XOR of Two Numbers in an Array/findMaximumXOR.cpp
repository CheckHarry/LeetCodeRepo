#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;



int findMaximumXOR(vector<int>& nums){
    int ans = 0;
    unordered_set<int> used;
    for (int i = 31 ; i >= 0 ; i --){
        ans = 2 * ans ;
        for (int num : nums) used.insert((num >> i));
        for (int num : nums){
            if (used.find((num >> i) ^ (ans + 1)) != used.end()){
                ans += 1;
                break;
            }
        }
        used.clear();
    }
    return ans;
}

int main(){
    vector<int> x{14,70,53,83,49,91,36,80,92,51,66,70};
    cout << findMaximumXOR(x);
}