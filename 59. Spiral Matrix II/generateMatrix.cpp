#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> ans(n, vector<int>(n, 0));
    vector<int> mapping{0, n - 1, n - 1, 0};
    int count = 1, state = 0;
    for (int a = 0; a < 2 * n - 1; a++)
    {
        state = a % 4;
        if (state == 0)
        {
            for (int i = mapping[3]; i <= mapping[1]; i++, count++)
                ans[mapping[state]][i] = count;
            mapping[state]++;
        }
        else if (state == 1)
        {
            for (int i = mapping[0]; i <= mapping[2]; i++, count++)
                ans[i][mapping[state]] = count;
            mapping[state]--;
        }
        else if (state == 2)
        {
            for (int i = mapping[1]; i >= mapping[3]; i--, count++)
                ans[mapping[state]][i] = count;
            mapping[state]--;
        }
        else if (state == 3)
        {
            for (int i = mapping[2]; i >= mapping[0]; i--, count++)
                ans[i][mapping[state]] = count;
            mapping[state]++;
        }
    }
    return ans;
}