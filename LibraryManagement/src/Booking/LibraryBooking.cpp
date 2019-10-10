#pragma once
#include <iostream>
#include "../Library/Book.cpp"
#include "../LibraryMembers/LibraryMember.cpp"

class LibraryBooking
{
private:
	int bookingID;
	Book *borrowedBook;
	LibraryMember *borrowedMember;

public:
	LibraryBooking(LibraryMember *borrowedMember, Book *book)
	{
		this->bookingID = rand();
		this->borrowedMember = borrowedMember;
		this->borrowedBook = book;
	}
	
	//get borrowed book id
	int getBorrowedBookID() { return this->borrowedBook->getBookID(); }
	
	//get borrowed member id
	int getBorrowedMemberID() { return this->borrowedMember->getMemberID(); }

	//display booking details
	void displayBookingDetails()
	{
		cout << "Book Borrowed is" << getBorrowedBookID() << endl;
		cout << "Book Borrowed by " << getBorrowedMemberID() << endl;
	}
};