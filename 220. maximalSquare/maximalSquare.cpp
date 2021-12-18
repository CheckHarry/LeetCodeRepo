#include <vector>
#include <array>
#include <iostream>
#include <set>
using namespace std;







int maximalSquare(vector<vector<char>>& matrix) {
    array<array<int, 301>, 301> dp;
    set<int> S;
    int max = 0;
    for (int i = 0; i < matrix[0].size(); i++) { dp[0][i] = matrix[0][i] == '1' ? 1 : 0; S.insert(dp[0][i]); }
    for (int i = 1; i < matrix.size(); i++) {
        dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
        S.insert(dp[i][0]);
        for (int j = 1; j < matrix[0].size(); j++) {
            dp[i][j] = matrix[i][j] == '1' ? min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1 : 0;
            S.insert(dp[i][j]);
        }
    }
    set<int>::iterator max_ = --S.end();

    return (*max_) * (*max_);
}