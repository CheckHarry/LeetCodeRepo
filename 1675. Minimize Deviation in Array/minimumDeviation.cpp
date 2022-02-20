#include <vector>
#include <queue>
#include <iostream>
using namespace std;


int minimumDeviation(vector<int>& nums) {
    priority_queue<int> Q;
    int Min = INT_MAX , ans = INT_MAX;
    for (int i = 0 ; i < nums.size() ; i ++) { 
        if(nums[i] % 2) nums[i] *= 2;
        Q.push(nums[i]);
        Min = min(nums[i] , Min);
    }
    if (Q.top() == Min) return 0;
    while (true){
        if (Q.top() % 2 != 0) break;
        else{
            Min = min(Q.top() / 2 , Min);
            Q.push(Q.top() / 2);
            Q.pop();
            ans = min(ans , Q.top() - Min);
        }
    }
    return ans;
}

int main() {
    vector<int> x{3,5};
    cout << minimumDeviation(x);
}

