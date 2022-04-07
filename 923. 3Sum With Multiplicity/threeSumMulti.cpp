#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


#define MOD_NUM 1000000007

int threeSumMulti(vector<int> &arr, int target)
{
    unordered_map<int, int> count;
    vector<int> eles;
    int ans = 0;
    for (int i : arr)
    {
        if (count[i] == 0)
            eles.push_back(i);
        count[i]++;
    }
    sort(eles.begin(), eles.end());
    for (int i = 0; i < eles.size(); i++)
    {
        for (int j = i; j < eles.size(); j++)
        {
            if ((target - eles[i] - eles[j]) >= eles[j] && count.find(target - eles[i] - eles[j]) != count.end())
            {
                long long a = count[eles[i]]--;
                long long b = count[eles[j]]--;
                int rem = target - eles[i] - eles[j];
                int div = 1;
                if (eles[i] == eles[j] && eles[j] == rem)
                {
                    div = 6;
                }
                else if (eles[i] == eles[j] || eles[i] == rem || eles[j] == rem)
                {
                    div = 2;
                }
                ans = (ans + a * b * count[target - eles[i] - eles[j]] / div) % MOD_NUM;
                count[eles[i]]++;
                count[eles[j]]++;
            }
        }
    }
    return ans;
}