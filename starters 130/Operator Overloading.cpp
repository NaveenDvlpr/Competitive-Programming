#include<bits/stdc++.h>
using namespace std;

class Box {
	
private:
	double length;
	double breadth;
	double height;
	
public: 
	double getVolume() {
		return length*breadth*height;
	}	
	void setLength(double len) {
		length = len;
	}
	void setBreadth(double bre) {
		breadth = bre;
	}
	void setHeight(double hei) {
		height = hei;
	}
	Box operator+(const Box &b) {
		Box box;
		box.length = this->length+b.length;
		box.breadth = this->breadth+b.breadth;
		box.height = this->height+b.height;
		return box;
	}
};

int main() {
	Box Box1, Box2, Box3;
	double volume = 0.0;
	
	Box1.setLength(6.0);
	Box1.setBreadth(7.0);
	Box1.setHeight(5.0);
	
	volume = Box1.getVolume();
	cout << "Volume of Box1: " << volume << endl;
	
	Box2.setLength(12.0);
	Box2.setBreadth(13.0);
	Box2.setHeight(10.0);
	
	volume = Box2.getVolume();
	cout << "Volume of Box2: " << volume << endl;
	
	Box3 = Box1 + Box2;
	
	volume = Box3.getVolume();
	cout << "Volume of Box3: " << volume << endl; 
}
























