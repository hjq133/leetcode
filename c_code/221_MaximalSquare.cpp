#include<bits/stdc++.h>
using namespace std;

int dp[101][101];
int maximalSquare(vector<vector<char>>& matrix) {
    int max_l = 0;
    for(int i = 0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[i].size(); j++) {
            if(matrix[i][j] == '1') {
                if(i == 0 || j == 0) {
                    dp[i][j] = 1;  // matrix[i][j] 肯定为1
                }
                else {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
            }
            max_l = max(max_l, dp[i][j]);
        }
    }
    return max_l * max_l;
}

int main() {

}