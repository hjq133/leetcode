#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
        int slow=0, fast=0;
        while(fast < nums.size()) {
            while(fast<nums.size() && nums[fast]!=0) {
                nums[slow++] = nums[fast++];
            }
            fast++;
        }
        while(slow<nums.size()) nums[slow++] = 0;
    }

int main() {

}