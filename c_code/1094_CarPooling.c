//处理所有行程，将乘客数量添加到开始位置，并从结束位置删除它。在处理完所有的行程后，特定地点的正值表明我们的客流量增加了;负-更多的空座位。
#include <stdio,h>

int location[1001] = {0};

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
	int i, total = 0;
	for(i = 0; i < tripsSize; i++) {
		location[trips[i][1]] += trips[i][0];
		location[trips[i][2]] -= trips[i][0];
	}
	for(i=1; i<1001; i++) {
		total += location[i];
		if(total < 0) return false;
	}
	return true;
}

int main() {
	int trips = {{2,1,5},{3,3,7}};
	int cap = 4;
	int colSize[2] = {3, 3};
	if(carPooling(trips, 2, colSize, cap)) {
		printf("yes\n");
	}
	printf("false\n");
}