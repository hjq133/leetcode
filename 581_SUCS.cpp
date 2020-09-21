#include<bits/stdc++.h>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    if(nums.size() == 1) return 0;
    int i = 0, j = nums.size() - 1;
    for(; i < nums.size()-1; i++) {
        if(nums[i] > nums[i+1]) break;
    }
    for(; j>0; j--) {
        if(nums[j] < nums[j-1]) break;
    }
    return max(j - i + 1, 0);
}

int main() {

}