#include <vector>
#include <algorithm>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    vector<pair<int, int>> record;
    vector<int> ans;
    for (int i = 0; i < mat.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == 1)
                count++;
            else
                break;
        }
        record.push_back({count, i});
    }
    sort(record.begin(), record.end(), [](const pair<int, int> &x, const pair<int, int> &y)
         {
            if (x.first != y.first) 
                return x.first < y.first;
            else 
                return x.second < y.second; });
    for (int i = 0; i < k; i++)
        ans.push_back(record[i].second);
    return ans;
}