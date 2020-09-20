#include <bits/stdc++.h>
using namespace std;

// 动态规划
// dp[i][j] 表示以i开头以j结尾的字符串是否是回文串
int dp[1010][1010];
int countSubstrings(string s) {
    int cnt = 0;
    for(int i=0; i<s.length(); i++) {
        dp[i][i] = 1;
        cnt++;
        if(i != 0) dp[i][i-1] = 1;
    }
    for(int sz=1; sz<s.length(); sz++) {
        for(int i=0; i<s.length()-sz; i++) {
            int j = i + sz;
            if(dp[i+1][j-1] == 1 && s[i] == s[j]) {
                dp[i][j] = 1;
                cnt++;
            }else {
                dp[i][j] = 0;
            }
        }
    }
    return cnt;
}

int main() {

}