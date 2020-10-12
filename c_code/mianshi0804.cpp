#include <bits/stdc++.h>
using namespace std;

vector<int> tmp;
vector<vector<int>> res;
void dfs(int cur, vector<int>& nums, int maxl) {
    if(tmp.size() == maxl) {
        res.push_back(tmp);
        return;
    }
    for(int i=cur; i<nums.size(); i++) {
        tmp.push_back(nums[i]);
        dfs(i+1, nums, maxl);
        tmp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    for(int sz=0; sz <= nums.size(); sz++)
        dfs(0, nums, sz);
    return res;
}