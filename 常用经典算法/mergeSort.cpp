#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, int lo, int hi, int mid) {
    int i, j;
    vector<int> temp;
    for(i=lo, j=mid+1; (i <= mid)&&(j <= hi); ) {
        if(a[i] > a[j]) {
            temp.push_back(a[j]);
            j++;
        }else {
            temp.push_back(a[i]);
            i++;
        }
    }
    while(i <= mid) {
        temp.push_back(a[i]);
        i++;
    }
    while(j <= hi) {
        temp.push_back(a[j]);
        j++;
    }
    for(i=0, j=lo; j <= hi; i++, j++) {
        a[j] = temp[i];
    }
}

void merge_sort(vector<int>& a, int lo, int hi) {
    int mid = lo + (hi - lo) / 2;
    int i, j;
    if(hi == lo) return;
    if(hi > lo) {
        merge_sort(a, lo, mid);
        merge_sort(a, mid+1, hi);
        merge(a, lo, hi, mid);
    }
}

int main() {
    int n, temp;
    vector<int> a = {22, 333, 4};
    merge_sort(a, 0, a.size()-1);
    for(int i=0; i<a.size(); i++) {
        cout<<a[i]<<endl;
    }
    return 0;
}