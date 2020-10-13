#include <bits/stdc++.h>
using namespace std;

// int singleNumber(vector<int>& nums) {
//     int single = 0;
//     for(int i=0; i<nums.size(); i++) {
//         single ^= nums[i];
//     }
//     return single;
// }

int singleNumber(vector<int>& nums) {
    unordered_map<int, int> m;
    int result = 0;
    for(int i=0; i<nums.size(); i++) {
        m[nums[i]] ++;
    }
    unordered_map<int, int>::iterator it = m.begin();
    for(; it != m.end(); it++) {
        if(it->second == 1) return it->first;
    }
}

int main() {

}