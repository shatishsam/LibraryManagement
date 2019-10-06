#pragma once
#include <list>
#include "../Library/Book.cpp"
#include "Person.cpp"

class LibraryMember :public Person
{
private:
	//data members
	int memberID;
	int booksBorrowed;
	std::list<Book> borrowedBooks;
	LibraryConstants::MemberState memberState;

public:
	//member functions
	LibraryMember(std::string Name, std::string Email, int mobileNumber) : Person(Name, Email, mobileNumber)
	{
		this->memberID = rand();
		this->booksBorrowed = 0;
		this->borrowedBooks.clear();
		this->memberState = LibraryConstants::MemberState::Active;
	}

	//get member ID
	int getMemberID() { return this->memberID; }

	//get books borrowed
	int getBooksBorrowed() { return this->booksBorrowed; }

	//get member state
	LibraryConstants::MemberState getMemeberState() { return this->memberState; }

	//set member state
	void setMemberState(LibraryConstants::MemberState memberState) { this->memberState = memberState; }

	//borrow books from Library
	bool borrowBook(int bookID)
	{

	}
};