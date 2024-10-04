#include<bits/stdc++.h>
using namespace std;

// Link Variables and Alias Variables
// Copy constructors and Operator Overloading
// Implicit Pointer Constants
// Read Only Pointers
// datatype &variable = another_variable;
// Every reference variable should be initialised at the time of declaration

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 100;
	int &b = a;
	int &c = b;
	c = 200;
	
	cout << a << ends <<  b << ends << c << endl;
}























