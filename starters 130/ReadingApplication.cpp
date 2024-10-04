#include<bits/stdc++.h>
using namespace std;

class Book {
private:
	string Book_ID;
	string Book_Name;
	int Page_Count;
	int On_Page;
public: 
	Book() {
		
	}
	
	Book(string id, string name, int count) {
		Book_ID = id;
		Book_Name = name;
		Page_Count = count;
		On_Page = 1;
	}
	void setBookName(string name) {
		Book_Name = name;
	}
	string getBookName() {
		return Book_Name;
	}
	int getPageCount() {
		return Page_Count;
	}
	
	int getOnPage() {
		return On_Page;
	}
	
	void setOnPage(int page) {
		if(page < 1) {
			cout << "No previous page exists" << endl;
			return;	
		}
		if(page > Page_Count) {
			cout << "Reached to end of the Book. Closing the Book" << endl ;
			page = 0;
		} 
		On_Page = page;
	}
};

class User {
private:
	string User_ID;
	string User_Name;
	unordered_map<string, Book> Books;
	string ActiveBookID;
public:
	User() {
		
	}
	
	User(string id, string name) {
		User_ID = id;
		User_Name = name;
		cout << "User Created Successfully..." << endl;
	}
	
	~User() {
		cout << "User Deleted Successfully..." << endl;
	}
	
	void setName(string name) {
		User_Name = name;
	}
	 
	string getName() {
		return User_Name;
	}
	
	string getID() {
		return User_ID;
	}
	
	string getActiveBookID() {
		return ActiveBookID;
	}
	
	void openBook(string bookID) {
		ActiveBookID = bookID;
	}
	
	void closeBook() {
		ActiveBookID = "";
	}
	
	void readBook() {
		cout << "Reading Book: " << Books[ActiveBookID].getBookName() << " on Page: " << Books[ActiveBookID].getOnPage() << endl;   
	}
	
	void addBook(string bookID, string bookName, int pages) {
		Book B(bookID, bookName, pages);
		Books[bookID] = B;
		cout << "Book Added Successfully..." << endl;
	}
	
	void deleteBook(string bookID) {
		if(bookID == ActiveBookID) closeBook(); 
		auto it = Books.find(bookID);
		Books.erase(it);
		cout <<"Book Deleted Successfully..." << endl;
	}
	
	void showBooks() {
		if(!Books.size()) {
			cout << "No Books present for User" << endl;	
			return;
		}
		cout << "<<< Showing Books >>>" << endl;
		for(auto book : Books) {
			cout << book.first << "  " << book.second.getBookName() << endl;
		}
		cout << endl;
	}
	
	
	void gotoNextPage() {
		Books[ActiveBookID].setOnPage(Books[ActiveBookID].getOnPage()+1);
	} 
	
	void gotoPreviousPage() {
		Books[ActiveBookID].setOnPage(Books[ActiveBookID].getOnPage()-1);
	}
};

class Library{
public:
	
	unordered_map<string, User> Users;
	
	Library() {
		cout << "Welcome to Naveen's Online Book Manager" << endl << endl;
	}
	
	void createUser(string id, string name) {
		User U(id, name);
		Users[id] = U;
	} 
	
	void deleteUser(string id) {
		Users[id].~User();
		auto it = Users.find(id);
		Users.erase(it);
	}
	
	void manageUser(string id) {
		cout << endl << "Welcome " << Users[id].getName() << endl;
		
		while(1) {
			bool activeBook = false;
			if(Users[id].getActiveBookID() != "") activeBook = true;
			
			if(activeBook) {
				Users[id].readBook();
			}
			cout << "----Press----" << endl;
			cout << "0. Leave Application" << endl;
			cout << "1. Add Book" << endl;
			cout << "2. Delete Book" << endl;
			cout << "3. Open Book" << endl;
			cout << "4. Show Books" << endl;
			if(activeBook) {
				cout << "5. Close Book" << endl;
				cout << "6. Go to Next Page" << endl;
				cout << "7. Go to Previous Page" << endl;
			}
			int ch;
			cin >> ch;
			if(ch == 0) {
				cout << "Thanks " << Users[id].getName() << ". Come Again." << endl;
				return;
			}
			if(ch < 1 || ch > 7 || (ch > 4 && !activeBook)) cout << "Choose a valid Option" << endl;
			else if(ch == 1) {
				string bookID, bookName;
				cout << "Enter Book ID: ";
				cin >> bookID;
				cout << "Enter Book Name: ";
				cin >> bookName;
				int pages;
				cout << "Enter Page Count: ";
				cin >> pages;
				Book B(bookID, bookName, pages);
				Users[id].addBook(bookID, bookName, pages);
			} else if(ch == 2) {
				string bookID;
				cout << "Enter Book ID to Delete: ";
				cin >> bookID;
				Users[id].deleteBook(bookID);
			} else if(ch == 3) {
				string bookID;
				cout << "Enter Book to Open: ";
				cin >> bookID;
				Users[id].openBook(bookID);
			} else if(ch == 4) {
				Users[id].showBooks();
			} else if(ch == 5) {
				Users[id].closeBook();
			} else if(ch == 6) {
				Users[id].gotoNextPage();
			} else {
				Users[id].gotoPreviousPage();
			}
		}
	}
	
	void showUsers() {
		if(!Users.size()) {
			cout << "No Users Yet" << endl;
			return;
		}
		for(auto user : Users) {
			cout << user.first << " " << user.second.getName() << endl;
		}
	}
};

int main() {
	Library lib;
	while(1) {
		cout << "----Press----" << endl;
		cout << "1. Create User" << endl;
		cout << "2. Delete User" << endl;
		cout << "3. Serve User" << endl;
		cout << "4. Show Users" << endl;
		cout << "5. Exit Application" << endl;
		int ch;
		cin >> ch;
		if(ch == 1) {
			string id, name;
			cout << "Enter User ID: ";
			cin >> id;
			cout << "Enter User Name: ";
			cin >> name;
			lib.createUser(id, name);
		} else if(ch == 2) {
			string id;
			cout << "Enter User ID to delete: ";
			cin >> id;
			lib.deleteUser(id);
		} else if(ch == 3) {
			string id;
			cout << "Enter User ID to access: ";
			cin >> id;
			User *user = &lib.Users[id];
			cout << user->getName() << " with ID: " << user->getID() << " is online" << endl;
			lib.manageUser(id);
		} else if(ch == 4) {
			lib.showUsers();
		}else if(ch == 5) {
			cout << endl << endl << "Exited Successfully..." << endl;
			break;
		} else {
			cout << "Enter a valid Input" << endl;
		}
	}
	
	return 0;
}



















