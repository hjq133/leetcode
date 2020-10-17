#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
vector<int> lst;

void dfs(int start, int step, int sz, vector<int>& nums) {
    if(step == sz) {
        res.push_back(lst);
        return;
    }
    for(int i=start; i<nums.size(); i++) {
        lst.push_back(nums[i]);
        dfs(i+1, step+1, sz, nums);
        lst.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    for(int sz=0; sz<=nums.size(); sz++) {
        dfs(0, 0, sz, nums);
    }
    return res;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = subsets(nums);
    for(int i = 0; i < res.size(); i++) {
        for(int j=0; j < res[i].size(); j++) {
            cout<<res[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}