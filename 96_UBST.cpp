#include <bits/stdc++.h>

// 动态规划，划分
// 1....n 作为序列，依次以i作为顶点，1...i-1 为左子树，i+1....n为右子树
// 能保证每个树都是唯一的

// dp公式：dp[n] = sum(1->n) (dp[i-1] * dp[n-i])
// 注意dp[0] = dp[1] = 1
int numTrees(int n) {
    int dp[n+1], sum=0;
    dp[0] = 1;
    dp[1] = 1;
    for(int len=2; len<=n; len++) {
        sum = 0;
        for(int i=1; i<=len; i++) {
            sum += (dp[i-1] * dp[len-i]);
        }
        dp[len] = sum;
    }
    return dp[n];
}