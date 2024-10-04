#include<bits/stdc++.h>
using namespace std;

class emp {
	int eid;
	string ename;
	float salary;
	
	void getemp() {
		cout << "Enter employee id, name and salary: ";
		cin >> eid >> ename >> salary;
	}
public:
	void putemp() {
		getemp();
		cout << eid << ends << ename << ends << salary << endl;
	}
};

int main() {
	emp e;
	e.putemp();
	return 0;
}
