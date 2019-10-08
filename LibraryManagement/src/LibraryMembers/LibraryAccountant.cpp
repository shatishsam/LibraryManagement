#pragma once
#include <unordered_set>
#include "../Library/Library.cpp"
#include "LibraryMember.cpp"

class LibraryAccountant : public Person
{

private:
	//data members
	int memberID;
	Library* libraryObject = NULL;

public:
	//member functions
	LibraryAccountant(std::string Name, std::string Email, int mobileNumber) : Person(Name, Email, mobileNumber)
	{
		this->memberID = rand();
		this->libraryObject = new Library("Zoho Library");
	}

	/*methods relating to Accountant*/
private:
	//get memer ID
	int getMemberID() { return this->memberID; }

	/*methods relating to LibraryMember*/
private:
	//throw error
	static void throwLibraryError(string errorMessage)
	{
		std::cerr << errorMessage << endl;;
	}

	

public:
	//block library member and remove from validated list
	void blockLibraryMember(LibraryMember* member) 
	{
		libraryObject->blockLibraryMember(member);
	}

	//unblock library member
	void unblockLibraryMember(LibraryMember* member) 
	{
		libraryObject->unblockLibraryMember(member);
	}

	/*methods relating to Library*/
private:
	//add new rack to the library
	void addRack()
	{
		libraryObject->addRack();
	}

public:
	//display library name
	void displayLibraryName() { cout << this->libraryObject->getLibraryName() << endl; }

	//display books
	void displayBooks(LibraryMember member) { libraryObject->displayBooks(member); }

	//add books to Library
	void tryaddBook(LibraryMember member, string title, string author, string category) { libraryObject->tryaddBook(title, author, category, member); }

	//search book by title
	void getTitleBook(LibraryMember member, string titleName) { libraryObject->getTitleBook(titleName, member); }

	//search book by author
	void getAuthorBook(LibraryMember member, string authorName) { libraryObject->getAuthorBook(authorName, member); }

	//search book by category
	void getCategoryBook(LibraryMember member, string categoryName) { libraryObject->getCategoryBook(categoryName, member); }

	//lend book to LibraryMember
	void lendBookToLibraryMember(LibraryMember* member, int bookID) { libraryObject->lendBookToLibraryMember(bookID, member); }

	//return book from LibraryMember
	void returnBookFromLibraryMember(LibraryMember* member, int bookID) { libraryObject->returnBookFromLibraryMember(bookID, member); }
};