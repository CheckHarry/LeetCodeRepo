#include <vector>
using namespace std;

int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
{
    vector<vector<vector<int>>> DP(
        houses.size() + 1,
        vector<vector<int>>(
            n + 1, vector<int>(target + 1, 0)));
    int ans = INT_MAX;
    for (int k = 1; k < target + 1; k++)
    {
        for (int c = 1; c < n + 1; c++)
        {
            if (k == 1)
            {
                DP[0][c][k] = houses[0] == c ? 0 : cost[0][c - 1];
            }
            else
            {
                DP[0][c][k] = INT_MAX / 2;
            }
        }
    }

    for (int i = 0; i < houses.size() - 1; i++)
    {
        for (int k = 1; k < target + 1; k++)
        {
            for (int c = 1; c < n + 1; c++)
            {
                for (int cj = 1; cj < n + 1; cj++)
                {
                    if (c == cj)
                    {
                        DP[i + 1][cj][k] = min(DP[i][c][k] + (houses[i + 1] == cj ? 0 : cost[i + 1][cj - 1]), DP[i + 1][cj][k]);
                    }
                    else 
                    {
                        if (k + 1 < target + 1)
                            DP[i + 1][cj][k + 1] = min(DP[i][c][k] + (houses[i] == cj ? 0 : cost[i][cj - 1]), DP[i + 1][cj][k + 1]);
                    }
                }
            }
        }
    }
    for (int c = 1 ; c < n + 1; c ++)
    {
        ans = min(DP[houses.size() - 1][c][target] , ans);
    }


    return ans;
}