#pragma once
#include <string>
#include "../LibraryConstants/LibraryConstants.cpp"
using std::string;

class Book
{
private:
	int bookID;
	string Title;
	string Author;
	string Category;
	LibraryConstants::BookState bookState;

public:
	//constructor
	Book(string Title, string Author, string Category)
	{
		this->bookID = rand();
		this->Title = Title;
		this->Author = Author;
		this->Category = Category;
		this->bookState = LibraryConstants::BookState::Racked;
	}

public:
	int getBookID() { return bookID; }
	string getTitle() { return Title; }
	string getAuthor() { return Author; }
	string getCategory() { return Category; }
	LibraryConstants::BookState getBookState() { return this->bookState; }
};