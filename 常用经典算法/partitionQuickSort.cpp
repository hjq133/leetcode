#include <bits/stdc++.h>
using namespace std;

// 双向扫描实现快排
// 这里的end是实际的end
// 升序排序(partition 快速排序)
int partition(vector<int>& a, int begin, int end){ 
    int pivot = a[begin];
    while(begin < end) {
        while(begin < end && a[end] >= pivot)  // 注意这里必须加=
            end--;
        a[begin] = a[end];
        while(begin < end && a[begin] <= pivot)
            begin++;
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

vector<int> generateRandomArray(int n, int rangeL, int rangeR) {
	assert(rangeL <= rangeR);
	vector<int> arr; // 创建一个 n个元素的数组
	srand(time(NULL)); // 随机种子
	for (int i = 0; i < n; i++)
	    arr.push_back(rand() % (rangeR - rangeL + 1) + rangeL);
	return arr;
}

int check(vector<int>& nums) {
    for(int i=1; i<nums.size(); i++) {
        if(nums[i-1] > nums[i]) return 1;
    }
    return 0;
}

int main() {
    for(int i=0; i<1000; i++) {
        vector<int> a = generateRandomArray(100, 0, 100);
        quick_sort(a, 0, a.size()-1);
        if(check(a)) {
            cout<<"error"<<endl;
            break;
        }
    }
    cout<<"done"<<endl;
    return 0;
}