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
	std::unordered_set<int> validatedMembers;

public:
	//member functions
	LibraryAccountant(std::string Name, std::string Email, int mobileNumber) : Person(Name, Email, mobileNumber)
	{
		this->memberID = rand();
		this->validatedMembers.clear();
		this->libraryObject = new Library("Zoho Library");
	}

	/*methods relating to Accountant*/
private:
	//get memer ID
	int getMemberID() { return this->memberID; }

	/*methods relating to LibraryMember*/
private:
	//throw invalid user error
	static void throwLibraryError(string errorMessage)
	{
		std::cerr << errorMessage << endl;;
	}

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

public:
	//block library member and remove from validated list
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

	/*methods relating to Library*/
private:
	//add new rack to the library
	void addRack()
	{
		this->libraryObject->addRack();
	}

public:
	//display library name
	void displayLibraryName() { cout << this->libraryObject->getLibraryName() << endl; }

	//display books
	void displayBooks(LibraryMember member)
	{
		if (!validateLibraryMember(member)) { throwLibraryError(LibraryConstants::getInvalidMemberErrorMessage()); return; }
		this->libraryObject->displayBooks();
	}

	//add books to Library
	void tryaddBook(LibraryMember member, string title, string author, string category)
	{
		if (!validateLibraryMember(member)) { throwLibraryError(LibraryConstants::getInvalidMemberErrorMessage()); return; }
		if (this->libraryObject->tryaddBook(title, author, category)) { cout << title << " Book added Sucessfuly" << endl; }
		else cout << "Cannot add book as rack is full kindly add new rack" << endl;
	}

	//search book by title
	void getTitleBook(LibraryMember member, string titleName)
	{
		if (!validateLibraryMember(member)) { throwLibraryError(LibraryConstants::getInvalidMemberErrorMessage()); return; }
		this->libraryObject->getTitleBook(titleName);
	}

	//search book by author
	void getAuthorBook(LibraryMember member, string authorName)
	{
		if (!validateLibraryMember(member)) { throwLibraryError(LibraryConstants::getInvalidMemberErrorMessage()); return; }
		this->libraryObject->getAuthorBook(authorName);
	}

	//search book by category
	void getCategoryBook(LibraryMember member, string categoryName)
	{
		if (!validateLibraryMember(member)) { throwLibraryError(LibraryConstants::getInvalidMemberErrorMessage()); return; }
		this->libraryObject->getCategoryBook(categoryName);
	}

	//lend book to LibraryMember
	void lendBookToLibraryMember(LibraryMember member, int BookID)
	{

	}
};