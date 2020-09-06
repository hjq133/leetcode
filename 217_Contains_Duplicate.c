#include <stdio.h>
#include <stdbool.h> // 支持bool类型

int cmp(const void* a, const void* b) {
	return (*(int*)a) - (*(int*)b);
}

bool containsDuplicate(int* nums, int numsSize){
	qsort(nums, numsSize, sizeof(int), cmp); // 复杂度o(nlgn)
	int i;
	for(i=0; i<numsSize-1; i++) {
		if(*(nums+i) == *(nums+i+1)) {
			return true;
		}
	}
	return false;
}

int main() {
	int nums[10] = {1, 3, 4, 1, 2, 4};
	if(containsDuplicate(nums, 6)) {
		printf("yes\n");
	}
	return 0;
}