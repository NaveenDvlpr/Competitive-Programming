#include<bits/stdc++.h>
using namespace std;

class Student{
	int RollNo;
	string Name;
	string ParentName;
	string MobileNo;
	int sub[6];
public:
	Student(int rollNo, string name, string parentName, string mobile) {
		RollNo = rollNo;
		Name = name;
		ParentName = parentName;
		MobileNo = mobile;
		for(int i = 0; i < 6; i++) sub[i] = 0;
	}
	void setRollNo(int rollNo) {
		RollNo = rollNo;
	}
	int getRollNo() {
		return RollNo;
	}
	string getName() {
		return Name;
	}
	void setName(string name) {
		Name = name;
	} 
	string getParentName() {
		return ParentName;
	}
	void setParentName(string parentName) {
		ParentName = parentName;
	} 
	void setMobileNo(string mobile) {
		MobileNo = mobile;
	}
	string getMobileNo() {
		return MobileNo;
	}
};

class Class {
private:
	int StudentCount;
	int OrganisedDays;
	vector<Student> Students;
	vector<int> Attendance;
public:
	Class() {
		StudentCount = 0;
		OrganisedDays = 0;
	}
	void addStudent(string name, string parentName, string mobile) {
		StudentCount++;
		Student s(StudentCount,name,parentName,mobile);
		Students.push_back(s);
		Attendance.push_back(0);
	}
	int getStudentCount() {
		return StudentCount;
	}
	void printStudentDetails() {
		cout << StudentCount;
		if(StudentCount == 1) cout << " Student enrolled for the Class." << endl;
		else cout << " Students are enrolled for the Class." << endl;
		cout << "-----Details-----" << endl; 
		for(auto s : Students) {
			cout << s.getRollNo() << " " << s.getName() << endl;
		}
	}
	void OraganiseClass() {
		OrganisedDays++;
		takeAttendance();
		checkAttendanceReport();
	}
	void takeAttendance() {
		for(auto s : Students) {
			string name = s.getName();
			int rollNo = s.getRollNo();
			cout << "Is " << name << " present (1-Present / 0-Absent): ";
			bool present;
			cin >> present;
			if(present) Attendance[rollNo-1]++;
		}
	}
	void checkAttendanceReport() {
		cout << endl << "------Attendance Report------" << endl;
		for(int i = 0; i < StudentCount; i++) {
			Student s = Students[i];
			string name = s.getName();
			cout << name << " is present " << Attendance[i] << "days out of " << OrganisedDays << "days" << endl;
			
		}
	}
	void removeStudent(int rollNo) {
		if(rollNo > StudentCount) {
			cout << "Invalid RollNo" << endl;
			return;
		}
		for(int i = rollNo; i < StudentCount; i++) {
			Students[i-1] = Students[i]; 
			Students[i-1].setRollNo(Students[i].getRollNo()-1);
		}
		StudentCount--;
	}
};

int main() {
	Class CSE;
	CSE.addStudent("Javed","Mohammed","9807802233");
	CSE.addStudent("Neelima","Ramaroa","7890156789");
	CSE.printStudentDetails();
	CSE.OraganiseClass();
	CSE.addStudent("Poornima","Rakshit Gowda", "9000451234");
	CSE.addStudent("Raja Sekharan","Senthil", "9898454678");
	CSE.addStudent("Harsha","Ramarao","7890156789");
	CSE.OraganiseClass();
	CSE.printStudentDetails();
	CSE.addStudent("Hanuma","Pavan","9875461235");
	CSE.checkAttendanceReport();
	CSE.removeStudent(100);
	CSE.removeStudent(4);
	CSE.printStudentDetails();
	CSE.checkAttendanceReport();
	return 0;
}

























