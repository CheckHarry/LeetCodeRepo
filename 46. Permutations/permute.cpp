#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;




void dfs(vector<int> &nums ,vector<bool> &mask , vector<vector<int>>& to_return ,  vector<int>& vec ,int pos){
    for (int i = 0 ; i < nums.size() ; i ++){
        if (mask[i] == false){
            mask[i] = true;
            vec.push_back(nums[i]);
            if (pos == nums.size() - 1) to_return.push_back(vec);
            else dfs(nums , mask , to_return , vec , pos + 1);
            mask[i] = false;
            vec.pop_back();
            if (pos == nums.size() - 1) break;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums){
    vector<bool> mask(21 , false);
    vector<vector<int>> to_return;
    vector<int> vec;
    int pos = 0;
    dfs(nums , mask , to_return , vec , pos);
    return to_return;
}

int main(){
    vector<int> x{1,2,3,4};
    vector<vector<int>> t = permute(x);
    for (vector<int> vec : t){
        for (int i : vec) cout << i << ',';
        cout << '\n';
    }
}