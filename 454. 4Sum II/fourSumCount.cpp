#include <vector>
#include <unordered_map>
using namespace std;







int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int,int> numpair;
    int ans = 0;
    for (int x : nums1){
        for (int y : nums2){
            numpair[x+y] ++;
        }
    }
    for (int x : nums3){
        for (int y : nums4){
            if (numpair.find(-(x+y)) != numpair.end()) ans += numpair[-(x+y)];
        }
    }
    return ans;
}



int main(){

}