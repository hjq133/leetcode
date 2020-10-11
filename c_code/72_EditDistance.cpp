#include <bits/stdc++.h>
using namespace std;

// D[i][j] 表示word1前i个字符和word2前j个字符的编辑距离
int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();

    if(n * m == 0) return n + m;
    int D[n + 1][m + 1];
    for(int i=0; i<=n; i++) {
        D[i][0] = i;
    }
    for(int j=0; j<=m; j++) {
        D[0][j] = j;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            int d1 = D[i-1][j] + 1; // 加一个或者减一个
            int d2 = D[i][j-1] + 1;  // 减一个
            int d3 = D[i-1][j-1]; // 替换一个
            if(word1[i-1] != word2[j-1]) d3 += 1;
            D[i][j] = min(min(d1, d2), d3);
        }
    }
    return D[n][m];
}

int main() {

}