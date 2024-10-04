#include<bits/stdc++.h>
using namespace std;

class Test2;

class Test1 {
	int a;
public:
	void geta() {
		cout << "Enter A value: ";
		cin >> a;
	}
	
	friend void big(Test1, Test2);
};

class Test2 {
	int b;
public:
	void getb() {
		cout << "Enter B value: ";
		cin >> b;
	}
	friend void big(Test1, Test2);
};

void big(Test1 t1, Test2 t2) {
	if(t1.a > t2.b) cout << "A is big" << endl;
	else if(t2.b > t1.a ) cout << "B is big" << endl;
	else cout << "Both are equal" << endl;
}

int main() {
	Test1 t1;
	Test2 t2;
	t1.geta();
	t2.getb();
	big(t1, t2);
	return 0;
}


// friend function is not member of any class it can has access to private members 
// of a class which is friend too.
// No restriction on name
// we can declare friend function anywhere position not has any effect
// friend function declaration should be inside the class using friend keyword
// definition should be done outside the class without using the friend keyword
// friend functions having objects has arguements
// invoked like normal functions
// To access the private members we must have to use object name
