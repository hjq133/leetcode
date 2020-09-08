#include <bits/stdc++.h>
using namespace std;

// 用这个方法注意二分要收敛
int search(vector<int>& nums, int target) {
    int left = 0, right=nums.size()-1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < nums[right]) { // mid - right 有序
            if(nums[mid] < target && target <= nums[right]) {  // target 在该有序区间内
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else {  // left - mid 有序
            if(nums[left] <= target && target < nums[mid]) {  // target 在该有序区间内
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    return -1;
}
// 方法2：判断成功后采用二分搜索
// int search(vector<int>& nums, int target) {
//     int left = 0, right=nums.size()-1;
//     while(left <= right) {
//         int mid = (left + right) / 2;
//         if(nums[mid] < nums[right]) { // mid - right 有序
//             if(nums[mid] < target && target <= nums[right]) {  // target 在该有序区间内
//                  return binary_search(nums, mid, right, target)
//             } else {
//                 right = mid - 1;
//             }
//         } else {  // left - mid 有序
//             if(nums[left] <= target && target < nums[mid]) {  // target 在该有序区间内
//                 return binary_search(nums, mid, right, target)
//             } else {
//                 left = mid + 1;
//             }
//         }
//     }
//     return -1;
// }

int main() {
    
}