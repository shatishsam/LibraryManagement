#pragma once
#include <iostream>
class LibraryConstants
{
private:
	//data members
	static const int Max_Days_Borrowed = 10;
	static const int Fine_Amount = 10;
	static const int Max_Books_perRow = 10;
	static const int Max_Books_Borrowed = 10;

	//error messages
	static constexpr const char* invalidLibraryMemberError = "Member Has Been Blocked";
	static constexpr const char* noSuchBookExistsError = "No Such Book Exists For The Given Book ID";
	static constexpr const char* maxBooksBorrowedError = "User Has Already Borrowed Maximum Of 10 Books";
	static constexpr const char* noSuchBookBorrwedError = "User Has Not Borrowed Such Book";

public:
	//data members
	enum BookState
	{
		Borrowed, Racked
	};

	enum rackState
	{
		Full, Empty, Available
	};

	enum MemberState
	{
		Active, Blocked
	};

public:
	//member functions
	static int getMaxBorrowedDuration()
	{
		return Max_Days_Borrowed;
	}

	static int getFineAmount()
	{
		return Fine_Amount;
	}

	static int getMaxBooksPerRow()
	{
		return Max_Books_perRow;
	}

	static int getMaxBooksBorrowed()
	{
		return Max_Books_Borrowed;
	}

	static std::string getInvalidMemberErrorMessage()
	{
		return invalidLibraryMemberError;
	}

	static std::string getNoBookExistsErrorMessage()
	{
		return noSuchBookExistsError;
	}

	static std::string getMaxBooksBorrowedErrorMessage()
	{
		return noSuchBookExistsError;
	}

	static std::string noSuchBookBorrwedErrorMessage()
	{
		return noSuchBookBorrwedError;
	}
};