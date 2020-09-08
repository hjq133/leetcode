#include<bits/stdc++.h>
using namespace std;
// leetcode 上是找下标，不能用这个方法（排序会打乱index），如果要用这个方法还得建立个hash表
// 此方法还有错误，还待改进（重复数字问题）
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> a;
        for(int i=0; i<nums.size(); i++) {  // 建立hash表，反向查询索引（这种表可以在O(1)时间内判断某个数是否在数组中存在）
            a.insert(pair<int, int>(nums[i], i));
        }
        int left = 0, right = nums.size() - 1;
        sort(nums.begin(), nums.end());  // 数组排序 O(N logN)
        while(left < right) {
            if(nums[left] + nums[right] > target) {
                right --;
            } else if(nums[left] + nums[right] < target) {
                left ++;
            } else {
                res.push_back(a[nums[left]]);
                res.push_back(a[nums[right]]);
                break;
            }
        }
        return res;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = twoSum(nums, target);
    cout<<"结果"<<endl;
    for (auto r : res) {
        cout<< r << endl;
    }
}