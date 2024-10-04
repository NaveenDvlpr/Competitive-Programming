#include<bits/stdc++.h>
using namespace std;

class Author{ // container class
	string authorName;
	friend class Book;
};

class Book { // contained class
	string bookName;
	float bookPrice;
	Author author; // Composition (Process of definiing one class object in another class)
public:
	void getData() {
		cout << "Enter Author Name: ";
		cin >> author.authorName;
		cout << "Enter Book Name: ";
		cin >> bookName;
		cout << "Enter Book Price: ";
		cin >> bookPrice;
	}
	
	void showData() {
		cout << "Book Name: " << bookName << endl;
		cout << "Author Name: " << author.authorName << endl;
		cout << "Book Price: " << bookPrice << endl;
	}
};

int main() {
	Book b;
	b.getData();
	b.showData();
	
	return 0;
}
