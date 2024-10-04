#include<bits/stdc++.h>
using namespace std;


class Shape {
	protected:
		int width, height;
	public:
		Shape(int a, int b) {
			width = a;
			height = b;
		}
		virtual int area() {
			cout << "Parent Class Area: " << width*height <<  endl;
			return width*height;
		}
};

class Rectangle : public Shape {
	public:
		Rectangle(int a= 0, int b = 0) : Shape(a,b) {}
		
		int area() {
			cout << "Rectangle class area :" << width*height << endl;
			return width*height;
		}
};

class Triangle : public Shape {
	public:
		Triangle(int a = 0, int b = 0):Shape(a,b) {}
		
		int area() {
			cout << "Triangle class area: " << width*height/2 << endl;
			return width*height/2;
		}
};

int main() {
	Shape *shape;
	Rectangle rec(10, 7);
	Triangle tri(10,5);
	
	shape = &rec;
	
	shape->area();
	
	shape = &tri;
	
	shape->area();
}






































