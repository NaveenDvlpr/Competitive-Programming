#include<bits/stdc++.h>
using namespace std;

// Base Class Shape
class Shape {
public: 
	void setWidth(int w) {
		width = w;
	} 
	void setHeight(int h) {
		height  = h;
	}
protected: 
	int width;
	int height;		
};

//Base Class PaintCost
class PaintCost {
public: 
	int getCost(int area) {
		return area*70;
	}	
};

//Derived Class
class Rectangle: public Shape, public PaintCost {
public: 
 	int getArea() {
 		return width*height;
	 }

};

int main() {
	Rectangle Rect;
	int area;
	
	Rect.setWidth(5);
	Rect.setHeight(10);
	
	area = Rect.getArea();
	cout << "Total Area: " << area << endl;
	cout << "Total Paint Cost: " << Rect.getCost(area) << endl; 
	return 0;
}













