#include <bits/stdc++.h>
using namespace std;

vector<int> findRange(vector<int>& nums, int id, int target) {
    int left = id, right = id;
    vector<int> res;
    while(left >= 0 && nums[left] == target) left --;
    while(right < nums.size() && nums[right] == target) right ++;
    res.push_back(left + 1);
    res.push_back(right - 1);
    return res;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    int left = 0, right = nums.size()-1, mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if(nums[mid] == target) {
            res = findRange(nums, mid, target);
            return res;
        } else if(nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid -1;
        }
    }
    res.push_back(-1);
    res.push_back(-1);
    return res;
}

int main() {

}
