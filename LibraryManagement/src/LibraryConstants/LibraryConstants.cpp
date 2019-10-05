#pragma once

class LibraryConstants
{
private:
	//data members
	static const int Max_Days_Borrowed = 10;
	static const int Fine_Amount = 10;
	static const int Max_Books_perRow = 10;

public:
	//data members
	static enum BookState
	{
		Borrowed, Racked
	};

	static enum rackState
	{
		Full, Empty, Available
	};

	static enum MemberState
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
};