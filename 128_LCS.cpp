#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    unordered_map<int, int> m;
    for(int i=0; i<nums.size(); i++) {
        m.insert(pair<int, int>(nums[i], 1));
    }
    int maxlen = 1, tmplen = 1;
    for(int i=0; i<nums.size(); i++) {
        if(m.count(nums[i]-1) > 0) {  // 存在前驱
            continue;
        } else { // 开始计数
            tmplen = 1;
            int tmp = nums[i] + 1;
            while(m.count(tmp) > 0) {
                tmplen++;
                tmp = tmp + 1;
            }
            maxlen = max(maxlen, tmplen);
        }
    }
    return maxlen;
}

int main() {

}