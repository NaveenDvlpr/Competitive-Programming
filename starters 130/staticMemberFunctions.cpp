#include<bits/stdc++.h>
using namespace std;

class Test {
public:
	static void read(int x, int y) {
		if(x > y) cout << "x is big";
		else if(y > x) cout << "y is big";
		else cout << "both are equal";
		cout << endl;
	}
};

int main() {
	Test::read(2,3);
	Test t1;
	t1.read(3,2);
	return 0;
}


// They are designed to work with static data members only they doesn't
// work on non static members
// they never associated with this pointer
// they associated with the class name and object name
// they should not be constant or volatile

