#include<bits/stdc++.h>
using namespace std;

class test {
	int a, b;
public:
	void getData();
	void putData();
	test sum(test);
};

void test::getData() {
	cout << "Enter A, B values: ";
	cin >> a >> b;
}

void test::putData() {
	cout << "A: " << a << " B: " << b << endl;
}

test test::sum(test t) {
	test t2;
	t2.a = a + t.a;
	t2.b = b + t.b;
	return t2;
}

int main() {
	test t1, t2, t3;
	t1.getData();
	t2.getData();
	t1.putData();
	t2.putData();
	t3 = t1.sum(t2);
	t3.putData();
	
	return 0;
}
