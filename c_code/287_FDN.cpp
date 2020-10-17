#include <bits/stdc++.h>
using namespace std;
int cmp(int a, int b) {
    return a > b;
}

int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] == nums[i+1])
                return nums[i];
        }
        return 0;
}

int main() {

}