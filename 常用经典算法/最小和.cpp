// 两个数组，在o(nlogn)内实现代码
// 二分查找的复杂度为o(logn)

#include <bits/stdc++.h>
using namespace std;

// 升序排序(partition 快速排序)
int partition(vector<int>& a, int begin, int end){ 
    int pivot = a[0];
    while(begin < end) {
        while(begin < end && a[end] >= pivot) {
            end--;
        }
        a[begin] = a[end];
        while(begin < end && a[begin] <= pivot) {
            begin++;
        }
        a[end] = a[begin];
    }
    a[begin] = pivot;
    return begin;
}

void quick_sort(vector<int>& a, int begin, int end) {
    if(begin >= end) return;
    int mid = partition(a, begin, end);
    quick_sort(a, begin, mid-1);
    quick_sort(a, mid+1, end);
}

bool cmp(int a, int b) {
    return a < b;
}

// O(n2)
int func1(vector<int>& a, vector<int>& b) {
    int sum = 0;
    for(int i=0; i<a.size(); i++) {
        for(int j=0; j<b.size(); j++) {
            sum += min(a[i], b[j]);
        }
    }
    return sum;
}

// O(nlogn)
// 快排 + 二分
int func2(vector<int>& a, vector<int>& b) {
    vector<int>::iterator id;
    int sum = 0;
    sort(a.begin(), a.end(), cmp);
    vector<int> a_sum;
    for(auto num: a) {
        sum += num;
        a_sum.push_back(sum);
    }
    sum = 0;
    for(int i=0; i<b.size(); i++) {
        id = lower_bound(a.begin(), a.end(), b[i]);
        sum += a_sum[(id-a.begin())-1];
        sum += (a.end() - id) * b[i];
    }
    return sum;
}

// 随机生成一个数组
vector<int> generateRandomArray(int n, int rangeL, int rangeR) {
	assert(rangeL <= rangeR);
	vector<int> arr; // 创建一个 n个元素的数组
	srand(time(NULL)); // 随机种子
	for (int i = 0; i < n; i++)
	    arr.push_back(rand() % (rangeR - rangeL + 1) + rangeL);
	return arr;
}

int main() {
    for(int i=0; i<1000; i++) {
        vector<int> a = generateRandomArray(100, 0 ,200);
        vector<int> b = generateRandomArray(100, 0 ,200);
        int sum1 = func1(a, b);
        int sum2 = func2(a, b);
        if(sum1 != sum2) {
            cout<<"error"<<endl;
            break;
        }
    }
    cout<<"done"<<endl;
}