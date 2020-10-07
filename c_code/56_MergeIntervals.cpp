#include <bits/stdc++.h>
using namespace std;

bool cmp(vector <int>& a, vector<int> &b) {
    return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end(), cmp);
    int begin, end;
    for(int i=0; i<intervals.size(); i++) {
        begin = intervals[i][0];
        end = intervals[i][1];
        while(i<intervals.size()-1 && end >= intervals[i+1][0]) {
            end = max(end, intervals[i+1][1]);
            i++;
        }
        res.push_back({begin, end});
    }
    return res;
}

int main() {
    vector<vector<int>> intervals = {{2, 3}, {4,5}, {6,7}, {8,9}, {1, 10}};
    vector<vector<int>> res = merge(intervals);
}