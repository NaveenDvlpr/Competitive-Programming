#include<bits/stdc++.h>
using namespace std;

class Student {
	int id, subMarks[6];
	string name;
public:
	void getStudent();
	void result();
};

void Student::getStudent() {
	cout << "Enter student id and name: ";
	cin >> id >> name;
	cout << "Enter subject marks: ";
	for(int i = 0; i < 6; i++) cin >> subMarks[i];
}

void Student::result() {
	bool pass = true;
	for(int i = 0; i < 6; i++) {
		if(subMarks[i] < 40) {
			pass = false;
			break;
		}
	}
	cout << name << "is " << (pass ? "passed" : "failed"a) << " the exam" << endl;
}

int main() {
	Student s[5];
	for(int i = 0; i < 5; i++) s[i].getStudent();
	for(int i = 0; i < 5; i++) s[i].result();
	return 0;
}
