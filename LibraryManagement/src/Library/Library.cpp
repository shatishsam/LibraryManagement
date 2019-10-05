#pragma once

#include <vector>
#include <iostream>
#include "Rack.cpp"
using std::cout; using std::endl;

class Library
{
private:
	//data members
	std::string libraryName;
	std::vector<Rack> Racks;

public:
	//member functions
	Library(std::string libraryName)
	{
		this->libraryName = libraryName;
		this->Racks.clear();
	};

public:
	//display books at all rack
	void displayBooks()
	{
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
	bool tryaddBook(string title, string author, string category)
	{
		bool isAdded = false;
		for (int i = 0; i < Racks.size(); i++)
		{
			if (Racks[i].getRackState() == LibraryConstants::Full) continue;
			Racks[i].addBook(Book(title, author, category));
			isAdded = true;
		}
		return isAdded;
	}

	//search book by title
	void getTitleBook(string titleName)
	{
		for (auto& IT : Racks)
		{
			if (IT.getRackState() == LibraryConstants::Empty) continue;
			IT.getTitleBook(titleName);
		}
	}

	//search book by author
	void getAuthorBook(string authorName)
	{
		for (auto& IT : Racks)
		{
			if (IT.getRackState() == LibraryConstants::Empty) continue;
			IT.getAuthorBook(authorName);
		}
	}

	//search book by category
	void getCategoryBook(string categoryName)
	{
		for (auto& IT : Racks)
		{
			if (IT.getRackState() == LibraryConstants::Empty) continue;
			IT.getCategoryBook(categoryName);
		}
	}

};
