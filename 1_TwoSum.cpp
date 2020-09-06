#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> a;
        for(int i=0; i<nums.size(); i++) {  // 建立hash表，反向查询索引（这种表可以在O(1)时间内判断某个数是否在数组中存在）
            a.insert(pair<int, int>(nums[i], i));
        }
        for(int i=0; i<nums.size(); i++) {  // 循环遍历，复杂度O(n)
            if((a.count(target-nums[i]) > 0) && (a[target-nums[i]] != i)) {  // 用hash表进行查找，复杂度为O(1)
                res.push_back(i);
                res.push_back(a[target-nums[i]]);
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