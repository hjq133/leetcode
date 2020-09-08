#include<bits/stdc++.h>
using namespace std;
// 回朔算法，dfs
vector<vector<char>> mp = {{' '},{' '}, {'a', 'b', 'c'}, {'d','e','f'}, {'g','h','i'}, {'j','k','l'}, {'m','n','o'},{'p','q','r','s'},{'t','u','v'}, {'w','x','y','z'}};
char res[20];
vector<string> re;

void func(int step, int len, string digits) {
    if(step == len) {
        res[step] = '\0';
        re.push_back(res);
        return;
    }
    int num = digits[step] - '0';
    for(auto ch : mp[num]) {
        res[step] = ch;
        func(step+1, len, digits);
    }
}

vector<string> letterCombinations(string digits) {
    int len = digits.length();
    if(len != 0)
        func(0, len, digits);
    return re;
}

int main() {
    string digits = "23";
    letterCombinations(digits);
    cout<<"hh"<<endl;
    return 0;
    // for(int i=0; i<mp.size(); i++) {
    //     for(int j=0; j<mp[i].size(); j++) {
    //         cout<<mp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
}