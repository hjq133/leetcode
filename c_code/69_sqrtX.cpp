#include <bits/stdc++.h>
using namespace std;

// 二分法
// int mySqrt(int x) {
//     int left = 0, right = x, mid;
//     while(left <= right) {
//         mid = (left + right) / 2;
//         long long temp = (long long)mid * mid;  // 注意这里防止溢出
//         if(temp == x) {
//             return mid;
//         }else if(temp < x) {
//             left = mid + 1;
//         }else {
//             right = mid - 1;
//         }
//     }
//     return right;
// }

// 牛顿法, 注意C==0的情况
int mySqrt(int C) {
    if(C == 0) return 0;
    double x_new, x_old;
    x_old = C;  // 随机初始值
    while(1) {
        x_new = (x_old + C/x_old) / 2;
        if(abs(x_new - x_old) < 1e-4)
            return int(x_new);
        x_old = x_new;
    }
}

int main() {

}