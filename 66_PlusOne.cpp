#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int flag = 0;
    for(int i=digits.size()-1; i>=0; i--) {
        if(i == digits.size()-1) flag += 1;
        digits[i] = digits[i] + flag;
        if(digits[i] >= 10) flag = 1;
        else flag = 0;
        digits[i] = digits[i] % 10;
    }
    if(flag) {
        vector<int> res;
        res.push_back(flag);
        for(int i=0; i<digits.size(); i++) res.push_back(digits[i]);
        return res;
    }else {
        return digits;
    }
}

int main() {

}