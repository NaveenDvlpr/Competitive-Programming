#include<bits/stdc++.h>
using namespace std;

int func(int (*mat)[3][5]) {
	
}

int main() {
	int mat[3][3][5];
	
	int (*pmat)[3][5] = mat;
	
	int a = 10;
	int *p1 = &a;
	int **p2 = &p1;
	
	cout << **p2 << endl;
	
	func(mat);
	
	return 0;
}
