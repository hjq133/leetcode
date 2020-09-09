#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;
    vector<vector<string>> res;
    for(auto str : strs) {
        string  ss = str;
        sort(ss.begin(), ss.end());
        m[ss].push_back(str);
    }
    unordered_map<string, vector<string>>::iterator it;
    for(it = m.begin(); it != m.end(); it++) {
        res.push_back(it->second);
    }
    return res;
}

int main() {
    
}