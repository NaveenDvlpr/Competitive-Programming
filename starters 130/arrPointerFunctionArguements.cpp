#include<stdio.h>

int SumOfElements(int A[]) {
	int n = sizeof(A)/sizeof(A[0]);
	printf("%d\n", n);
	int i, sum = 0;
	for(i = 0; i < n; i++) sum += A[i];
	return sum;
}

int main() {
	int A[] = {1, 2, 3, 4, 5};
	int total = SumOfElements(A);
	printf("%d", total);
	return 0;
}
