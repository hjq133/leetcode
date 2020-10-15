#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    unordered_set<char> set;
    for(int i=0; i<s.length(); i++) {
        if(set.count(s[i]) > 0)
            return i;
        set.insert(s[i]);
    }
    return -1;
}

int main() {

}