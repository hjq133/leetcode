#include <bits/stdc++.h>
using namespace std;
// 没过
int partition(vector<int>& nums, int begin, int end) {
    int pivot = nums[begin];
    while(begin < end) {
        while(begin < end && nums[end] >= pivot) {
            end--;
        }
        nums[begin] = nums[end];
        while(begin < end && nums[begin] <= pivot) {
            begin++;
        }
        nums[end] = nums[begin];
    }
    nums[begin] = pivot;
    return begin;
}

int missingNumber(vector<int>& nums) {
    int begin = 0, end = nums.size()-1;
    int k;
    while(begin <= end) {
        k = partition(nums, begin, end);
        if(k == nums[k]) {
            k += 1;
            begin = k;
            end = end;
        }else {
            k -= 1;
            end = k;
            begin = begin;
        }
    }
    return k+1;
}

int main() {

}