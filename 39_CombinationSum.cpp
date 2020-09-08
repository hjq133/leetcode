#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
vector<int> lst;

void dfs(vector<int>& candidates, int target, int start) {
    for(int i=start; i<candidates.size(); i++) {
        if(target < candidates[i]) {
            continue;
            // return;  // 如果用sort这里就用return，但是不用sort更快
        } else if(target == candidates[i]) {
            lst.push_back(candidates[i]);
            res.push_back(lst);
            lst.pop_back();
        } else {
            lst.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i);
            lst.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    // sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0);
    return res;
}

int main() {

}