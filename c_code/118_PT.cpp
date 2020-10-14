#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    if(numRows == 0) return res;
    res.push_back({1});
    for(int i=2; i<=numRows; i++) {
        vector<int> tmp;
        tmp.push_back(1);
        for(int j=1; j<i-1; j++) {
            tmp.push_back(res[i-2][j-1] + res[i-2][j]);
        }
        tmp.push_back(1);
        res.push_back(tmp);
    }
    return res;
}

int main() {
    generate(3);
    return 0;
}