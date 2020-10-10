#include <bits/stdc++.h>
using namespace std;
int hammingWeight(uint32_t n) {
    int sum = 0;
    while(n != 0) {
        sum += n % 2;
        n = n / 2;
    }
    return sum;
}

int main() {
    int a = 23;
    printf("%d\n", a/ 2);
    return 0;
}