#include<bits/stdc++.h>
using namespace std;

class Monitor {
	int height,width;
	string type;
	
public:
	
	Monitor() {
		height = 720;
		width = 1080;
		type = "CRT";
	}
	
	Monitor(int height, int width) : Monitor() {
		this->height = height;
		this->width = width;
	}
	
	Monitor(int height, int width, string type) : Monitor(height, width) {
		this->type = type;
	}
	
	Monitor(Monitor &old) {
		height = old.height;
		width = old.width;
		type = old.type;
	}
	
	~Monitor() {
		cout << "Monitor Destroyed" << endl;
	}
	
	void showDimensions() {
		cout << type << " Monitor with dimensions " << height << "x" << width << endl;
	}
};

// Constructors never participate in inheritance 
// They make to implicit calls to new and delete operators
// Constructors can have default arguements
// Constructors can be overloaded
// We cannot find the address of the constructor
// Constructors are executed only once when the object is created further callings are not 
// allowed
// They never invoked with object name
// Initialise the object and provide resources to the data members
// Constructor are need to be declared in public section only
// Default Constructor , Paramaterised Constructor , Copy Constructor
// Compiler adds a constructor without any code if no constructor found
// Compiler Written Constructor
// Destructors never contain arguements so overloading is not possible
// Destructors never participate in inheritance
// Copy constructors we use reference type parameters and class type parameters
// Copy Constructor is possible by operator overloading

int main() {
	
	Monitor m;
	m.showDimensions();
	Monitor m2(546, 800);
	m2.showDimensions();
	Monitor m3(900, 1250, "LED");
	m3.showDimensions();
	Monitor m4(m3);
	m4.showDimensions();
	return 0;
}













