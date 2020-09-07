#include <bits/stdc++.h>
using namespace std;
// 最大盛水量 -> 双指针法

int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1, maxA = 0, h, A;
    while(i < j) {
        h = min(height[i], height[j]);
        A = h * (j - i);
        maxA = max(maxA, A);
        if(height[i] < height[j]) {
            i += 1;
        }else {
            j -= 1;
        }
    }
    return maxA;
}

int main() {
    vector<int> a = {1,8,6,2,5,4,8,3,7};
    int area = maxArea(a);
    cout<< area << endl;
    return 0;
}
