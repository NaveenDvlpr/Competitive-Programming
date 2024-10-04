#include<bits/stdc++.h>
using namespace std;

// new and delete

int main() {
////	int *p;
////	float *q;
////	char *r;
////	p = new int(5);
////	q = new float(1.4);
////	r = new char('g');
//	int n;
//	cin >> n;
//	
//	int *arr;
//	arr = new int[n];
//	
//	for(int i = 0; i < n; i++) cin >> *(arr+i);
//	for(int i = 0; i < n; i++) cout << *(arr+i) << endl;
//	
//	delete arr;


	int **mat, nr, nc, r, c;
	cin >> nr >> nc;
	
	mat = new int*[nr];
	
	for(int i = 0; i < nr; i++) {
		mat[i] = new int[nc];
	}
	
	for(int i = 0; i < nr; i++) {
		for(int j = 0; j < nc; j++) cin >> *(*(mat+i)+j);
	}
	
	for(int i = 0; i < nr; i++) {
		for(int j = 0; j < nc; j++) cout << *(*(mat+i)+j) << " ";
		cout << endl;
	}
	
	delete mat;
	
	for(int i = 0; i < nr; i++) {
		for(int j = 0; j < nc; j++) cout << *(*(mat+i)+j) << " ";
		cout << endl;
	}
	
	
	return 0;
}


// dynamic memory allocation is used for memory and performance efficiency





























