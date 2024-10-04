#include<bits/stdc++.h>
using namespace std;

class Passenger {
private:
	string name;
	int age;
	string u_id;
	string password;
public:
	Passenger(string name, int age, string u_id, string password) {
		this->name = name;
		this->age = age;
		this->u_id = u_id;
		this->password;
	}
	Passenger(string name, string u_id, string password) {
		this->name = name;
		this->u_id = u_id;
		this->password = password;
		age = -1;
	}
};

class PassengerManager {
private:
	unordered_map<string, Passenger> passengerList; 
public:
	
	bool checkPassenger(string u_id) {
		return false;
	}
	
	bool confirmPassword(string password, string conPassword) {
		if(password == conPassword) return true;
	}
	
	bool isValidPassword(string password) {
		if(password.length() < 8 || (password[0]-'0' >= 0 && password[0]-'0' <= 9)) return false;
		bool small = false, big = false;
		for(int i = 0; i < password.length() && !(small && big); i++) {
			if(password[i] >= 'a' && password[i] <= 'z') small = true;
			if(password[i] >= 'A' && password[i] <= 'Z') big = true;
		}
		if(small && big) return true;
		return false;
	}
	
/*	void createPassenger() {
		string name, u_id, password, conPassword;
		int age;
		cout << "Enter your u_id: ";
		cin >> u_id;
		if(checkPassenger(u_id)) {
			cout << "Account alredy exists for the given ID" << endl;
			return;
		}
		cout << "Enter your name: ";
		cin >> name;
		cout << "Enter your Password\n(length greater than 8 not starts with a number and has both small and capital leterr in it): ";
		cin >> password;
		while(!isValidPassword(password)) {
			cout << "Entered Password is not strong pls follow the conditions" << endl;
			cout << "(length greater than 8 not starts with a number and has both small and capital leterr in it): ";
			cin >> password;	
		} 
		cout << "Re-enter your Password: ";
		while(!confirmPassword(password, conPassword)) {
			cout << "Entered Password not matches please re-enter: ";
			cin >> conPassword;	
		}
		Passenger passenger(name, age, u_id, password);
		passengerList[u_id] = passenger;
		cout << "User Added Successfully";
	} */
	
	void createPassenger() {
		Passenger p("Naveen",25,"6949","Nanigadu@1");
		passengerList[p.u_]
	}
	 
};


int main() {
	PassengerManager PM;
	PM.createPassenger();
}































































































