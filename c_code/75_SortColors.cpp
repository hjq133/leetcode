#include <bits/stdc++.h>
using namespace std;
// 算法1：通过1次扫描计算0,1的个数，再通过1次扫描重写数组
// 算法2:   通过1次扫描, 3个指针，计算边界并交换数据

void sortColors(vector<int>& nums) {
    int a = 0, b = 0;
    for(int i=0; i<nums.size(); i++) {
        if(nums[i] == 0) a++;
        else if(nums[i] == 1) b++;
    }
    b += a;
    for(int j=0; j<nums.size(); j++) {
        if(j < a) nums[j] = 0;
        else if(j < b) nums[j] = 1;
        else nums[j] = 2;
    }
}

int main() {

}