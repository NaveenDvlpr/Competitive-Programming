#include<stdio.h>

int main() {
	int A[] = {2,4,5,8,1};
	int i;
	int *p = A;
	p++;
	printf("%d\n", *p);
	for(int i = 0; i < 5; i++) {
		printf("%d\n", A+i);
		printf("%d\n", &A[i]);
		printf("%d\n", A[i]);
		printf("%d\n\n\n", *(A+i));
	}
	return 0;
}
