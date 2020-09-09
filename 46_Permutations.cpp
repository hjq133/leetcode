#include <bits/stdc++.h>
using namespace std;

int used[200];
int step=0;
vector<vector<int>> res;
vector<int> lst;

void dfs(vector<int>& nums, int step) {
    if(step == nums.size()) {
        res.push_back(lst);
    }
    for(int i=0; i<nums.size(); i++) {
        if(used[i] == 0) { // 没用过
            lst.push_back(nums[i]);
            used[i] = 1;
            dfs(nums, step+1);
            used[i] = 0;
            lst.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    dfs(nums, 0);
    return res;
}

int main() {

}