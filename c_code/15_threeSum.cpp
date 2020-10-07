#include <bits/stdc++.h>
using namespace std;

// 三数之和
// 采用双指针法解题，hash表法不太适用

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    if(nums.size() < 3) return ans; // 判断数组大小
    sort(nums.begin(), nums.end());  // 数组排序 O(N logN)
    for(int i=0; i<nums.size()-2; i++) {
        if(nums[i] > 0) break;
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int left = i+1, right = nums.size() - 1;
        while(left < right) {
            if(nums[left] + nums[i] + nums[right] > 0) // 说明nums[right]太大了
                right --;
            else if(nums[left] + nums[i] + nums[right] < 0) {  // 说明nums[left]太小了
                left ++;
            } else { // 找到了满足要求的了, 但要避免出现重复
                ans.push_back({nums[i], nums[left], nums[right]});
                // 相同的left和right不应该再次出现，因此跳过
                while(left < right && nums[left] == nums[left+1])
                    left ++;
                while(left < right && nums[right] == nums[right-1])
                    right --;
                left ++;
                right --;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(nums);
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++) {
            cout<< res[i][j] <<endl;
        }
    }
    return 0;
}