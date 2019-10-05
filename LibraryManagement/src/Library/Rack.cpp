#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <thread>
#include "Book.cpp"
using std::cout; using std::endl;

class Rack
{
private:
	int rackID;
	std::unordered_map<int, Book> Books;
	std::unordered_multimap<string, std::list<Book>> titleMap;
	std::unordered_multimap<string, std::list<Book>> authorMap;
	std::unordered_multimap<string, std::list<Book>> categoryMap;
	LibraryConstants::rackState rackState;

public:
	Rack()
	{
		this->rackID = rand();
		this->Books.clear();
		this->titleMap.clear();
		this->authorMap.clear();
		this->categoryMap.clear();
		this->rackState = LibraryConstants::rackState::Empty;
	}

private:
	//is title present
	bool isTitlePresent(string Title)
	{
		if (titleMap.find(Title) == titleMap.end()) return false;
		return true;
	}

	//is author present
	bool isAuthorPresent(string Author)
	{
		if (authorMap.find(Author) == authorMap.end()) return false;
		return true;
	}

	//is category present
	bool isCategoryPresent(string Category)
	{
		if (categoryMap.find(Category) == categoryMap.end()) return false;
		return true;
	}

	//add books to title map
	void addBookToTitleMap(Book book)
	{
		if (isTitlePresent(book.getTitle()))
		{
			auto IT = titleMap.find(book.getTitle());
			(*IT).second.push_back(book);
		}
		else
		{
			std::list<Book> titleBooks; titleBooks.push_back(book);
			titleMap.insert(std::pair<string, std::list<Book>>(book.getTitle(), titleBooks));
		}
	}

	//add book to author map
	void addBookToAuthorMap(Book book)
	{
		if (isAuthorPresent(book.getAuthor()))
		{
			auto IT = authorMap.find(book.getAuthor());
			(*IT).second.push_back(book);
		}
		else
		{
			std::list<Book> authorBooks; authorBooks.push_back(book);
			authorMap.insert(std::pair<string, std::list<Book>>(book.getAuthor(), authorBooks));
		}
	}

	//add book to category map
	void addBookToCategoryMap(Book book)
	{
		if (isCategoryPresent(book.getCategory()))
		{
			auto IT = categoryMap.find(book.getCategory());
			(*IT).second.push_back(book);
		}
		else
		{
			std::list<Book> categoryBooks; categoryBooks.push_back(book);
			categoryMap.insert(std::pair<string, std::list<Book>>(book.getCategory(), categoryBooks));
		}
	}

public:
	//get Rack ID
	int getRackID()
	{
		return this->rackID;
	}

	//get Rack State
	LibraryConstants::rackState getRackState()
	{
		return this->rackState;
	}

	//display All Books which are not borrowed
	void displayBooks()
	{
		for (auto& IT : Books)
		{
			if (IT.second.getBookState() == LibraryConstants::BookState::Borrowed) continue;
			cout << IT.second.getTitle() << "->" << IT.second.getBookID() << endl;
		}
	}

	//display books with given title
	void getTitleBook(string Title)
	{
		if (!isTitlePresent(Title)) {cout << "no books with Title " << Title << endl; return;}
		//get books and print
		auto IT = titleMap.find(Title);
		for (auto& IT2 : (*IT).second)
		{
			cout << IT2.getTitle() << endl;
		}
	}

	//display books with given author name
	void getAuthorBook(string Author)
	{
		if (!isAuthorPresent(Author)) {cout << "no books with Author " << Author << endl; return;}
		//get books and print
		auto IT = authorMap.find(Author);
		for (auto& IT2 : (*IT).second)
		{
			cout << IT2.getTitle() << endl;
		}
	}

	//display books with given category name
	void getCategoryBook(string Category)
	{
		if (!isCategoryPresent(Category)) { cout << "no books with Category " << Category << endl; return;}
		//get books and print
		auto IT = categoryMap.find(Category);
		for (auto& IT2 : (*IT).second)
		{
			cout << IT2.getTitle() << endl;
		}
	}

	//add book to rack
	bool addBook(Book book)
	{
		//if rack is full return as we cannot add anymore books
		if (rackState == LibraryConstants::Full) return false;

		//add to the list of the books
		Books.insert(std::pair<int, Book>(book.getBookID(), book));

		/*add to the titlemap, authormap and categorymap*/
		std::thread t1(&Rack::addBookToTitleMap, this,  book); 
		std::thread t2(&Rack::addBookToAuthorMap, this, book);  
		std::thread t3(&Rack::addBookToCategoryMap, this, book);
		t1.join(); t2.join(); t3.join();

		//update the rack size
		if (Books.size()>= LibraryConstants::getMaxBooksPerRow()) rackState = LibraryConstants::rackState::Full;
		else rackState = LibraryConstants::rackState::Available;

		return true;
	}
};