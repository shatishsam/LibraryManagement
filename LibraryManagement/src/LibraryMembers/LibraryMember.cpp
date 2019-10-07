#pragma once
#include <list>
#include "../Library/Book.cpp"
#include "Person.cpp"

class LibraryMember :public Person
{
private:
	//data members
	int memberID;
	std::list<Book> borrowedBooks;
	LibraryConstants::MemberState memberState;

public:
	//member functions
	LibraryMember(std::string Name, std::string Email, int mobileNumber) : Person(Name, Email, mobileNumber)
	{
		this->memberID = rand();
		this->borrowedBooks.clear();
		this->memberState = LibraryConstants::MemberState::Active;
	}

	//get member ID
	int getMemberID() { return this->memberID; }

	//get books borrowed
	int getNumberOfBooksBorrowed() { return this->borrowedBooks.size(); }

	//get member state
	LibraryConstants::MemberState getMemeberState() { return this->memberState; }

	//set member state
	void setMemberState(LibraryConstants::MemberState memberState) { this->memberState = memberState; }
	
	//add book to user
	void addBorrowedBook(Book borrowedBook) { borrowedBooks.push_back(borrowedBook); }

	//display all borrowed book
	void displayBorrowedBooks()
	{
		for (auto IT : borrowedBooks)
		{
			cout << IT.getTitle() << " -> " << IT.getBookID() << endl;
		}
	}

	//check if the book is borrowed by the member
	bool isBookPresentWithMember(int BookID)
	{
		for (auto IT : borrowedBooks)
		{
			if (IT.getBookID() == BookID) return true;
		}
		return false;
	}
};