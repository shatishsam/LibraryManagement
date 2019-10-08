#pragma once
#include <iostream>
#include <vector>
#include "Rack.cpp"
#include "../LibraryMembers/LibraryMember.cpp"
using std::cout; using std::endl;

class Library
{
private:
	//data members
	std::string libraryName;
	std::vector<Rack> Racks;
	std::unordered_set<int> validatedMembers;

public:
	//member functions
	Library(std::string libraryName)
	{
		this->libraryName = libraryName;
		this->Racks.clear();
		this->validatedMembers.clear();
		addRack();
	};

private:
	//throw error
	static void throwLibraryError(string errorMessage)
	{
		std::cerr << errorMessage << endl;;
	}

	/*methods relating to library*/
public:
	//display books at all rack
	void displayBooks(LibraryMember member)
	{
		if (!validateLibraryMember(member)) { throwLibraryError(LibraryConstants::getInvalidMemberErrorMessage()); return; }
		for (int i = 0; i < Racks.size(); i++)
		{
			cout << "Displaying Books at RackID " << Racks[i].getRackID() << endl;
			Racks[i].displayBooks();
		}
	}

	//get library name
	std::string getLibraryName() { return this->libraryName; }

	//add new rack
	void addRack()
	{
		Rack newRack;
		Racks.push_back(newRack);
		cout << "Added new Rack RackID is" << newRack.getRackID() << endl;
	}

	//add books to rack which has free slot
	void tryaddBook(string title, string author, string category, LibraryMember member)
	{
		if (!validateLibraryMember(member)) { throwLibraryError(LibraryConstants::getInvalidMemberErrorMessage()); return; }

		bool isAdded = false;
		for (int i = 0; i < Racks.size(); i++)
		{
			if (Racks[i].getRackState() == LibraryConstants::Full) continue;
			Racks[i].addBook(Book(title, author, category));
			isAdded = true; cout << title << " Book added Sucessfuly" << endl;
		}
		if(!isAdded) cout << "Cannot add book as rack is full kindly add new rack" << endl;
	}

	//search book by title
	void getTitleBook(string titleName, LibraryMember member)
	{
		if (!validateLibraryMember(member)) { throwLibraryError(LibraryConstants::getInvalidMemberErrorMessage()); return; }

		for (auto& IT : Racks)
		{
			if (IT.getRackState() == LibraryConstants::Empty) continue;
			IT.getTitleBook(titleName);
		}
	}

	//search book by author
	void getAuthorBook(string authorName, LibraryMember member)
	{
		if (!validateLibraryMember(member)) { throwLibraryError(LibraryConstants::getInvalidMemberErrorMessage()); return; }

		for (auto& IT : Racks)
		{
			if (IT.getRackState() == LibraryConstants::Empty) continue;
			IT.getAuthorBook(authorName);
		}
	}

	//search book by category
	void getCategoryBook(string categoryName, LibraryMember member)
	{
		if (!validateLibraryMember(member)) { throwLibraryError(LibraryConstants::getInvalidMemberErrorMessage()); return; }

		for (auto& IT : Racks)
		{
			if (IT.getRackState() == LibraryConstants::Empty) continue;
			IT.getCategoryBook(categoryName);
		}
	}

	/*methods relating to Library Member*/
public:
	// validate the given user
	bool isValidLibraryMember(LibraryMember member) { return member.getMemeberState() == LibraryConstants::MemberState::Active; }

	//check if the member is validated already
	bool validateLibraryMember(LibraryMember member)
	{
		//check if already validated before
		if (validatedMembers.find(member.getMemberID()) == validatedMembers.end())
		{
			//if not present validate and add to validated members list
			if (!isValidLibraryMember(member)) return false;
			validatedMembers.insert(member.getMemberID());
		}
		return true;
	}

	//block library member
	void blockLibraryMember(LibraryMember* member)
	{
		member->setMemberState(LibraryConstants::MemberState::Blocked);
		validatedMembers.erase(member->getMemberID());
	}

	//unblock library member
	void unblockLibraryMember(LibraryMember* member)
	{
		member->setMemberState(LibraryConstants::MemberState::Active);
		validatedMembers.insert(member->getMemberID());
	}
	
	//lend book to a given library member
	void lendBookToLibraryMember(int bookid, LibraryMember* member)
	{
		//throw error if the member is invalid or the book has been borrowed already
		if (!validateLibraryMember(*member)) { throwLibraryError(LibraryConstants::getInvalidMemberErrorMessage()); return; }
		//throw error if member has already borrowed maximum books
		if(member->getNumberOfBooksBorrowed()>=LibraryConstants::getMaxBooksBorrowed()) { throwLibraryError(LibraryConstants::getMaxBooksBorrowedErrorMessage()); return; }

		//search on all the racks present at the library
		for (int i = 0; i < Racks.size(); i++)
		{
			Book* bookToLend = Racks[i].getBook(bookid);
			if (!bookToLend) continue;  //if book is found return or keep seraching in other racks

			//book is found update book state and add to the members book list
			bookToLend->setBookState(LibraryConstants::BookState::Borrowed);
			member->addBorrowedBook(bookToLend); 
			return;
		}

		//book is not found any of the racks print book not found error
		throwLibraryError(LibraryConstants::getNoBookExistsErrorMessage());
	}

	//return a book from member and change its state
	void returnBookFromLibraryMember(int bookID, LibraryMember* member)
	{
		//throw error if the member is invalid or the book has been borrowed already
		if (!validateLibraryMember(*member)) { throwLibraryError(LibraryConstants::getInvalidMemberErrorMessage()); return; }
		
		//throw error if member has no such book
		if(!member->isBookBorrowed(bookID)) { throwLibraryError(LibraryConstants::noSuchBookBorrwedErrorMessage()); return; }

		//remove the book from user and update its state
		member->returnBorrowedBook(bookID);
	}
};
