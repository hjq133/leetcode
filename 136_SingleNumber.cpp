#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int single = 0;
    for(int i=0; i<nums.size(); i++) {
        single ^= nums[i];
    }
    return single;
}

int main() {

}