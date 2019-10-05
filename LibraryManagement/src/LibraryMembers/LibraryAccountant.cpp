#pragma once
#include <unordered_set>
#include "../Library/Library.cpp"
#include "LibraryMember.cpp"

class LibraryAccountant : public Person
{
private:
	int memberID;
	Library* libraryObject = NULL;
	std::unordered_set<int> validatedMembers;

public:
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

	//throw invalid user error
	static void printInvalidMemberError()
	{
		perror("Member Not Validated Yet Kindly Validate By Calling Validate Member Method");
	}

	/*methods relating to LibraryMember*/
private:
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
		if (!validateLibraryMember(member)) { printInvalidMemberError(); return; }
		this->libraryObject->displayBooks();
	}

	//add books to Library
	void tryaddBook(LibraryMember member, string title, string author, string category)
	{
		if (!validateLibraryMember(member)) { printInvalidMemberError(); return; }
		if (this->libraryObject->tryaddBook(title, author, category)) { cout << title << " Book added Sucessfuly" << endl; }
		else cout << "Cannot add book as rack is full kindly add new rack" << endl;
	}

	//search book by title
	void getTitleBook(LibraryMember member, string titleName)
	{
		if (!validateLibraryMember(member)) { printInvalidMemberError(); return; }
		this->libraryObject->getTitleBook(titleName);
	}

	//search book by author
	void getAuthorBook(LibraryMember member, string authorName)
	{
		if (!validateLibraryMember(member)) { printInvalidMemberError(); return; }
		this->libraryObject->getAuthorBook(authorName);
	}

	//search book by category
	void getCategoryBook(LibraryMember member, string categoryName)
	{
		if (!validateLibraryMember(member)) { printInvalidMemberError(); return; }
		this->libraryObject->getCategoryBook(categoryName);
	}
};