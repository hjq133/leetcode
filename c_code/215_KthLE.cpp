#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& nums, int begin, int end) {
    int pivot = nums[begin];
    while(begin < end) {
        while (begin < end && nums[end] >= pivot)
            end--;
        nums[begin] = nums[end];
        while(begin < end && nums[begin] <=  pivot)
            begin++;
        nums[end] = nums[begin];
    }
    nums[begin] = pivot;
    return begin;
}

int findKthLargest(vector<int>& nums, int k) {
    k = nums.size() - k;
    int begin = 0, end = nums.size()-1;
    while(1) {
        int mid = partition(nums, begin, end);
        if(mid == k) return nums[k];
        else if(mid > k) end = mid-1;
        else begin = mid + 1;
    }
    return -1;
}