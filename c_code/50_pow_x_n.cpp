#include <bits/stdc++.h>
using namespace std;
// 快速幂算法
// 分治递归
double quickMul(double x, int N) {
    if(N == 0)
        return 1.0;
    double y = quickMul(x, N/2);
    if(N % 2 == 0)
        return y * y;
    else
        return y * y * x;
}

double myPow(double x, int n) {
    if(n >= 0)
        return quickMul(x, n);
    else
        return 1 / quickMul(x, n);
}