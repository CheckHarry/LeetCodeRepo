#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;




void dfs(vector<vector<int>> &to_return , vector<int> &candidates , vector<int> &vec , int pos , int sum , int target){
    if (pos >= candidates.size()) return;
    if (target >= sum + candidates[pos]){
        vec.push_back(candidates[pos]);
        if (target > sum + candidates[pos]) dfs(to_return , candidates , vec , pos , sum + candidates[pos] , target);
        else to_return.push_back(vec);
        vec.pop_back();
        dfs(to_return , candidates , vec , pos + 1, sum , target);
    }
    else return;
    

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin() , candidates.end());
    vector<vector<int>> to_return{};       
    vector<int> vec{};
    dfs(to_return , candidates , vec , 0 , 0 , target);
    return to_return;
}



int main(){
    vector<int> x{2,3,6,7};
    vector<vector<int>> y = combinationSum(x , 7);
    for (vector<int> a : y) {for(int k : a) cout << k << ','; cout << '\n';}
}