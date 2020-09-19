#include <bits/stdc++.h>
using namespace std;

// 双向扫描实现快排
// 这里的end是实际的end的下一位
int partition(vector<int>& a, int begin, int end) {
    int pivot = a[begin];
    while(begin < end) {
        while(begin < end && a[--end] >= pivot);
        a[begin] = a[end];
        while(begin < end && a[++begin] <= pivot);
        a[end] = a[begin]; 
    }
    a[begin] = pivot;
    return begin;
}

int quickSort(vector<int>& a, int begin, int end) {
    int mid = partition(a, 0, a.size());
    
}

int main() {
    vector<int> a = {4, 12, 1, 9, 8, 3, 0, 1};
    partition(a, 0, a.size());
    for(int i=0; i<a.size(); i++) {
        cout<<a[i]<<' ';
    }
    cout<<endl;
}