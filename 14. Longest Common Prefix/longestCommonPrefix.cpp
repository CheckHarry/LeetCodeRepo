#include <vector>
#include <string>
using namespace std;







string longestCommonPrefix(vector<string>& strs) {
    string ans = "";
    int count = 0;
    for (int i = 0 ; i < strs[0].size() ; i ++){
        int temp = 0;
        for (string& s : strs){
            if (i < s.size() && strs[0][i] == s[i]) temp ++;
            else break;
        }
        if (temp == strs.size()) ans += strs[0][i];
        else break;
    }
    return ans;
}