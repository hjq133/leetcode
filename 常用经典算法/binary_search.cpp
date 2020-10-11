#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> arr, int begin, int end, int target) {
    int mid;
    if(begin <= end) {
        mid = (begin + end) / 2;
        if(target == arr[mid])
            return mid;
        else if(target > arr[mid]) {
            return binary_search(arr, mid + 1, end, target);
        }else {
            return binary_search(arr, begin, mid - 1, target);
        }
    }
    return -1;
}

int main() {

}