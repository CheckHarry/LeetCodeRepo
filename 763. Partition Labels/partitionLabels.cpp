#include <vector>
#include <string>
using namespace std;








vector<int> partitionLabels(string s) {
    vector<int> count(26 , 0) , ans;
    int left = 0 , right = 0;
    for (int i = 0 ; i < s.size() ; i ++) count[s[i] - 'a'] = i;
    for (int i = 0 ; i < s.size() ; i ++){
        right = max(right , count[s[i] - 'a']);
            if (right == i) {
                ans.push_back(i - left + 1);
                left = i + 1;
            }
    }
    return ans;
}

