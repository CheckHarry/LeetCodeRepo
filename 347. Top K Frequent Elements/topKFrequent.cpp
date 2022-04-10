#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    auto cmp = [](pair<int, int> &x, pair<int, int> &y)
    {
        return x.second > y.second;
    };
    unordered_map<int, int> count;
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> Q(cmp);
    vector<int> to_return;

    for (int i : nums)
        count[i]++;

    for (auto it = count.begin(); it != count.end(); it++)
    {
        Q.push({it->first, it->second});
        if (Q.size() > k)
            Q.pop();
    }

    while (!Q.empty())
    {
        to_return.push_back(Q.top().first);
        Q.pop();
    }
    
    return to_return;
}