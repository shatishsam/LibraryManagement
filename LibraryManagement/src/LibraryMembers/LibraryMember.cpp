#pragma once
#include <unordered_map>
#include "../Library/Book.cpp"
#include "Person.cpp"

class LibraryMember :public Person
{
private:
	//data members
	int memberID;
	std::unordered_map<int, Book*> borrowedBooks;
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
	void addBorrowedBook(Book *borrowedBook) { borrowedBooks.insert(std::pair<int, Book*>(borrowedBook->getBookID(), borrowedBook)); }

	//display all borrowed book
	void displayBorrowedBooks()
	{
		for (auto IT : borrowedBooks)
		{
			cout <<IT.first  << " -> " << IT.second->getTitle() << endl;
		}
	}

	//check if the book is borrowed by the member
	bool isBookBorrowed(int bookID)
	{
		auto IT = borrowedBooks.find(bookID);
		return IT != borrowedBooks.end();
	}

	//remove book from borrowed list
	void returnBorrowedBook(int bookID)
	{
		//remove the book make sure to call the isbookborrowed before calling this method
		auto IT = borrowedBooks.find(bookID);
		try 
		{
			Book* borrowedBook = (*IT).second;
			borrowedBook->setBookState(LibraryConstants::BookState::Racked); //change the state of returned book
			borrowedBooks.erase(IT);
		}
		catch (...)
		{
			std::cerr << "No Such Book Present Exception" << endl;
		}
	}
};