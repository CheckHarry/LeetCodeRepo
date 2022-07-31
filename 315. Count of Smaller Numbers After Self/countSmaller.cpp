#include <vector>
using namespace std;


class Solution
{
public:
    int BIT[20002];

    int lowbit(int x)
    {
        return x & -x;
    }

    void add(int x, int k)
    {
        while (x < 20002)
        {
            BIT[x] = BIT[x] + k;
            x = x + lowbit(x);
        }
    }

    int getsum(int x)
    {
        int ans = 0;
        while (x >= 1)
        {
            ans += BIT[x];
            x = x - lowbit(x);
        }
        return ans;
    }

    vector<int> countSmaller(vector<int> &nums)
    {

        memset(BIT, 0, sizeof(BIT));
        vector<int> ans;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            ans.push_back(getsum(nums[i] + 10001 - 1));
            add(nums[i] + 10001, 1);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};