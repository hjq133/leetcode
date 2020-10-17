#include <bits/stdc++.h>
using namespace std;
int reverse(int x) {
    vector<int> res;
    while(x != 0) {
        res.push_back(x % 10);
        x = x / 10;
    }
    for(int i=0; i<res.size(); i++) {
        x = 10 * x + res[i];
    }
    return x;
}

int main() {

}