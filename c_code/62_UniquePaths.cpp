#include <bits/stdc++.h>
using namespace std;

// 用深度优先搜索太耗时了，用dp更快
int uniquePaths(int m, int n) {
    int dp[m+1][n+1];
    for(int i=1; i <=m; i++) {
        dp[i][1] = 1;
    }
    for(int j=1; j<=n; j++) {
        dp[1][j] = 1;
    }
    for(int i=2; i<=m; i++) {
        for(int j=2; j<=n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m][n];
}

int main() {
    int res = uniquePaths(3, 7);
    cout<<res<<endl;
    return 0;
}