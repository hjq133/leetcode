//  TODO 最长公共子序列
// # TODO 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度
// # 转移方程： if str1[i] == str2[j], dp[i][j] = dp[i-1][j-1] + 1
// #           else dp[i][j] = max(dp[i-1][j], dp[i][j-1])
# include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int dp[1000][1000] = {0};  // 注意不要用变量定义长度
    for(int i=1; i<=text1.length(); i++) {
        for(int j=1; j<=text2.length(); j++) {
            if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[text1.length()][text2.length()];
}

int main() {

}