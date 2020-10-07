#include <bits/stdc++.h>
using namespace std;

// 最长回文子串
// 解法1：动态规划
int dp[1001][1001]; // dp[i][j] = 1 表示 i -> j  (闭区间) 是回文串
// 若dp[i][j] == 1 且 s[i-1] == s[j+1], 则dp[i-1][j+1] = 1

string longestPalindrome(string s) {
    int len = s.length();
    int left = 0,  maxLen = 1;
    for(int i = 0; i<len; i++) {
        dp[i][i] = 1;
        dp[i+1][i] = 1;
    }
    for(int sz=2; sz<=len; sz++) { // s表示子串的长度，遍历每一种长度的可能情况
        for(int i=0; i+sz-1<len; i++) {
            int j=i+sz-1;
            if(dp[i+1][j-1] == 1 && (s[i] == s[j])) {  // 状态转移方程
                dp[i][j] = 1;
                if(sz > maxLen) {
                    maxLen = sz;
                    left = i;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return s.substr(left, maxLen);
}

int main() {
    string ss = "abcabc";
    string res = longestPalindrome(ss);
    cout<<res<<endl;
    return 0;
}