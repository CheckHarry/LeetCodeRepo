#include <vector>
using namespace std;



bool validMountainArray(vector<int>& arr) {
    if (arr.size() < 3) return false;
    int increase = 1;
    bool is_increase = false;
    for (int i = 0 ; i < arr.size() - 1 ; i ++){
        if (increase == 1){
            if (arr[i] == arr[i + 1]) return false;
            else if (arr[i] > arr[i + 1]) increase = -1;
            else is_increase = true;
            }
        else if (arr[i] <= arr[i + 1] || !is_increase) return false;  
    }
    if (increase == -1 && is_increase) return true;
    else return false;
}