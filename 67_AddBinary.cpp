#include<bits/stdc++.h>
using namespace std;

string cat(string temp, int len) {
    while(len--)
        temp += "0";
    return temp;
}

string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(a.length() > b.length())
        b = cat(b, a.length()-b.length());
    else
        a = cat(a, b.length()-a.length());
    string res = "";
    int flag = 0, tmp;
    for(int i=0; i<a.length(); i++) {
        tmp = a.at(i) - '0' + b.at(i) - '0' + flag;
        if(tmp >= 2) flag = 1;
        else flag = 0;
        res += ('0' + tmp % 2);
    }
    if(flag) res += '1';
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string res = addBinary("1111", "1111");
    return 0;
}