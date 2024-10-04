#include<bits/stdc++.h>
using namespace std;

class Student {
	int id, subject[6];
	string name;
	
public:
	void getStudent();
	void result();
};

void Student::getStudent() {
	cout << "Enter student id and name: ";
	cin >> id >> name;
	cout << "Enter 6 subjects marks: ";
	for(int i = 0; i < 6; i++) cin >> subject[i];
}

void Student::result() {
	int total = 0;
	for(int i = 0; i < 6; i++) total += subject[i];
	float average = total/6.0;
	cout << "Total: " << total << endl;
	cout << "Average: " << average << endl;
	cout << "Result: ";
	for(int i = 0; i < 6; i++) {
		if(subject[i] < 35) {
			cout << "Failed" << endl;
			return;
		}
	}
	if(average >= 80) cout << "First Class" << endl;
	else if(average >= 60) cout << "Second Class" << endl;
	else cout << "Pass Class" << endl;
}

int main() {
	Student s;
	s.getStudent();
	s.result();
	return 0;
}






























