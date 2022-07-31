

#include <vector>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    vector<int> mapping(256, -1);
    int left = 0, ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        left = max(mapping[c] + 1, left);
        ans = max(ans, i - left + 1);
        mapping[c] = i;
    }
    return ans;
}