#include<stdio.h>

int SumOfElements(int A[], int n) {
	printf("%d\n", &A);
	int i, sum = 0;
	for(i = 0; i < n; i++) sum += A[i];
	return sum;
}

int main() {
	int A[] = {1, 2, 3, 4, 5};
	printf("%d\n", &A);
	int n = sizeof(A)/sizeof(A[0]);
	int total = SumOfElements(A, n);
	printf("%d", total);
	return 0;
}
