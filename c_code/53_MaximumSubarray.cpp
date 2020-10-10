#include <bits/stdc++.h>
using namespace std;

// 最大子序列和
// 解法：动态规划
// 状态转移方程 ：f i = max ( f i-1 + a i,  a i )
// f i 表示以i结尾的连续子数组的最大和
// id记录这个数组结尾的位置，然后就可以找出这个数组了
int maxSubArray(vector<int>& nums) {
    int f = 0, max_sum = nums[0], id = 0;
    for(int i=0; i<nums.size(); i++) {
        f = max(nums[i], nums[i] + f);
        if(max_sum < f) {
            id = i;
            max_sum = f;
        }
    }
    return max_sum;
}
