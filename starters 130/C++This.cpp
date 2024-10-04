#include<bits/stdc++.h>
using namespace std;

class test {
	int a = 10, b = 20;
public:
	void show() {
		cout << "Obj Address is: " << this << endl;
		cout << "A = " << this->a << endl;
		cout << "B = " << this->b << endl;
	}
	void show(int a, int b) {
		this->a = a;
		this->b = b;
	}
};

// Local Variables have the highest Priority

int main() {
	
	test t;
	cout << "Obj Address is: " << &t << endl;
	t.show();
	t.show(30, 40);
	t.show();
	
	return 0;
}
