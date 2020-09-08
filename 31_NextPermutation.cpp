#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>& nums, int a, int b) {
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}

void nextPermutation(vector<int>& nums) {
    int target_s, target_l, flag=0;
    for(int i=nums.size()-1; i>0; i--) {
        if(nums[i] > nums[i-1]) { // 找到升序对了
            target_s = i-1;
            flag = 1;
            break;
        }
    }
    if(flag == 1) { // 存在升序对
        for(int i=nums.size()-1; i>=0; i--) {
            if(nums[target_s] < nums[i]) {
                target_l = i;
                break;
            } // 找到第1个比target_s 大的
        }
        swap(nums, target_s, target_l);
    } else { // 不存在升序对
        target_s = -1;
    }
    for(int i=target_s+1, j=nums.size()-1; i<j; i++, j--) {
        swap(nums, i, j);
    }
}

int main() {
    return 0;
}