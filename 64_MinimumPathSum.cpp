#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int dp[grid.size()][grid[0].size()];
    int sum = 0;
    for(int i=0; i<grid.size(); i++) {  // dp[]
        sum += grid[i][0];
        dp[i][0] = sum;
    }
    sum = 0;
    for(int j=0; j<grid[0].size(); j++) {  // dp[]
        sum += grid[0][j];
        dp[0][j] = sum;
    }
    for(int i=1; i<grid.size(); i++) {
        for(int j=1; j<grid[i].size(); j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    return dp[grid.size()-1][grid[0].size()-1];
}

int main() {
    vector<vector<int>> grid = {{1,3,1}, {1,5,1}, {4,2,1}};
    int res = minPathSum(grid);
    cout<<res<<endl;
}