#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int dp[nums.size() + 1];
    dp[0] = 1;
    for(int i=1; i<nums.size(); i++) {
        int max_l = 1;
        for(int j=0; j<i; j++) {
            if(nums[i] > nums[j]) {
                max_l = max(max_l, dp[j] + 1);
            }
        }
        dp[i] = max_l;
    }
    int res = 0;
    for(int i=0; i<nums.size(); i++) {
        res = max(res, dp[i]);
    }
    return res;
}

int main() {

}