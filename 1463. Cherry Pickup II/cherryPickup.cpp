#include <vector>
#include <iostream>
#include <cstring>
using namespace std;



int cherryPickup(vector<vector<int>>& grid) {
    int col_num =  grid[0].size() - 1 , Max = 0;
    int dp[71][71][71];
    memset(dp , 0 , sizeof(dp));
    for (int row = 0 ; row < grid.size() ; row ++){
        for (int i = 0 ; i < col_num + 1; i ++){
            for (int j = i ; j < col_num + 1 ; j ++ ){
                for (int k = -1 ; k < 2 ; k ++){
                    for (int l = -1 ; l < 2 ; l ++){
                    if ( 0 <= i + k && i + k <= col_num && 0 <= j + l && j + l <= col_num && i + k < 1 + row && j + l >= col_num - row && (i + k) != (j + l)) {
                        dp[row+1][i + k][j + l] = max(dp[row][i][j] + grid[row][i + k] + grid[row][j + l] , dp[row+1][i + k][j + l]);
                        }
                    }
                }
            }
    }
    }
    for(int i = 0 ; i < 71 ; i ++) for (int j = 0 ; j < 71 ; j ++) Max = max(Max , dp[grid.size()][i][j]);
    return Max;
}

int main(){
    vector<vector<int>> grid{{9,3,1,2},{9,9,2,2},{8,4,8,3},{9,2,7,7}};
    cout << cherryPickup(grid);
}