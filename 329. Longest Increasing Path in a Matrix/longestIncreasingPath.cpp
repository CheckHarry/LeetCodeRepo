#include <vector>
using namespace std;



int search(vector<vector<int>> &matrix , vector<vector<int>> &DP , int i , int j)
{
    if (DP[i][j] > 0)
        return DP[i][j];

    vector<int> s(4 , -1);
    
    if (i - 1 >= 0 && matrix[i][j] > matrix[i - 1][j])
        s[0] = search(matrix , DP , i - 1 , j);
    
    if (i + 1 < matrix.size() && matrix[i][j] > matrix[i + 1][j])
        s[1] = search(matrix , DP , i + 1 , j);

    if (j - 1 >= 0 && matrix[i][j] > matrix[i][j - 1])
        s[2] = search(matrix , DP , i , j - 1);

    if (j + 1 < matrix[0].size() && matrix[i][j] > matrix[i][j + 1])
        s[3] = search(matrix , DP , i , j + 1);

    int m = -1;
    for (int i : s)
        m = max(m , i);

    DP[i][j] = m == -1 ? 1 : m + 1;
    
    return DP[i][j];
}


int longestIncreasingPath(vector<vector<int>>& matrix) {
    vector<vector<int>> DP(matrix.size() , vector<int> (matrix[0].size() , -1));
    int ans = 0;
    for (int i = 0 ; i < matrix.size() ; i ++)
    {
        for (int j = 0 ; j < matrix[0].size() ; j ++)
            ans = max(search(matrix , DP , i , j) , ans);
    }
    return ans;
}