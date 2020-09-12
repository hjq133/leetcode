#include <bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    unordered_map<int, int> m;
    vector<int> res;
    for(int i=0; i<nums.size(); i++)
        m.insert(pair<int,int>(nums[i], 1));
    for(int i=1; i<=nums.size(); i++) {
        if(m.count(i) != 1)
            res.push_back(i);
    }
    return res;
}