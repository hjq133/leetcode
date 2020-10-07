#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    int left = 0, right = x, mid;
    while(left <= right) {
        mid = (left + right) / 2;
        long long temp = (long long)mid * mid;  // 注意这里防止溢出
        if(temp == x) {
            return mid;
        }else if(temp < x) {
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }
    return right;
}

int main() {

}