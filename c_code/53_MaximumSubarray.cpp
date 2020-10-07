#include <bits/stdc++.h>
using namespace std;

// 最大子序列和
// 解法：动态规划
// 状态转移方程 ：f i = max ( f i-1 + a i,  a i )

int maxSubArray(vector<int>& nums) {
    int pre = 0, maxAns = nums[0];
    for(auto num : nums) {
        pre = max(pre + num, num);
        maxAns = max(maxAns, pre);
    }
    return maxAns;
}

int main() {
    vector<int> nums= {-2,1,-3,4,-1,2,1,-5,4};
    int maxs = maxSubArray(nums);
    cout<<maxs<<endl;
    return 0;
}