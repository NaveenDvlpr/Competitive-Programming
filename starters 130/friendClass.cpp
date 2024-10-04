#include<bits/stdc++.h>
using namespace std;

class Test2;

class Test1 {
	int a, b;
public:
	friend class Test2;	
	void getab() {
		cout << "Enter A B values: ";
		cin >> a >> b;
	}
};

class Test2 {
public:
	void putab(Test1 t1) {
		cout << t1.a << " " << t1.b << endl;	
	}
};

int main() {
	Test1 t1;
	t1.getab();
	Test2 t2;
	t2.putab(t1);
	
	return 0;
}


// Access of whole class from another class
// Container Class or Declared Class
// Contained Class
// Composition allows the concept of reusability but not extensibility

