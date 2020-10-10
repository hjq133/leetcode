#include <bits/stdc++.h>
using namespace std;
int partition(vector<pair<int, int>>& val, int left, int right) {
    pair<int, int> pivot = val[left];
    while(left < right) {
        while(left < right && val[right].second <= pivot.second)
            right --;
        val[left] = val[right];
        while(left < right && val[left].second >= pivot.second)
            left++;
            val[right] = val[left];
    }
    val[right] = pivot;
    return right;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for(auto& v: nums) {
        m[v]++;
    }
    vector<pair<int, int>> val;
    for (auto& kv: m) {
        val.push_back(kv);
    }
    int mid, left = 0, right = val.size()-1;
    vector<int> res;

    while(1) {
        mid = partition(val, left, right);
        if(mid == k-1) break;
        else if(mid > k-1) {
            left = left;
            right = mid - 1;
        }else {
            left = mid + 1;
            right = right;
        }
    }

    for (int i=0; i<k; i++) {
        res.push_back(val[i].first);
    }

    return  res;
}
