#include <string>
#include <vector>
using namespace std;








vector<string> summaryRanges(vector<int>& nums) {
    if (nums.size() == 0) return vector<string> ();
    int cur = nums[0], count = 1;        
    vector<string> ans;
    string temp = std::to_string(cur);
    for (int i = 1 ; i < nums.size() ; i ++){
        if (nums[i] != cur + 1){
            if (count == 1) ans.emplace_back(move(temp));
            else ans.emplace_back(temp + "->" + std::to_string(cur));
            count = 1;
            temp = std::to_string(nums[i]);
        }
        else count ++;
        cur = nums[i];
    }
    if (count == 1) ans.emplace_back(move(temp));
    else ans.emplace_back(temp + "->" + std::to_string(cur));
    return ans;
}