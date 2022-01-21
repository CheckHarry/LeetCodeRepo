#include <vector>
#include <list>
#include <iostream>
using namespace std;





int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sum = 0;
    list<int> L;
    for (int i = 0 ; i < gas.size() ; i ++) {
        sum += gas[i] - cost[i];
        if (sum < 0) {
            L.push_back(sum);
            sum = 0;
        }
    }
    L.push_back(sum);
    if (&L.front() == &L.back()) {
        if (L.front() >= 0) return 0;
        else return -1;
    }
    for (int i = 0 ; i < gas.size() ; i ++){
        L.front() -= gas[i] - cost[i];
        L.back()  += gas[i] - cost[i];
        while(L.front() >= 0){
            *(L.begin() ++) += L.front();
            L.erase(L.begin());
            if (&L.front() == &L.back()) {
                if (L.front() < 0) return -1;
                else return (i + 1)%gas.size();
            }
        }
    }
    return -1;   
}

int main(){
    vector<int> gas{3,1,1} , cost{1,2,2};
    cout << canCompleteCircuit(gas ,cost);
}