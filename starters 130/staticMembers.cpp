#include<bits/stdc++.h>
using namespace std;

class Test {
	static int count = 0; // declaration part
public:
	Test() {
		count++;
		cout << count << " Object created" << endl;
	}
	~Test() {
		cout << count << " Object deleted" << endl;
		count--;
	}
};

//int Test::count; // definition part

int main() {
	Test t1, t2, t3;
	return 0;
}

// one class data member with static and default value is 0
// all the objects having 
// class members not object members
// a single copy is created and it is resided inside the class
// static members can be accessed directly with the class name
// className::static_member = value;
// declared and defined
// data segment which is public
// share one datamember all the objects of the class
