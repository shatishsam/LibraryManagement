#include <iostream>
#include "../Library/Library.cpp"
#include "../LibraryMembers/LibraryAccountant.cpp"
using namespace std;

void displayOptions()
{
	cout << "1 to display books at library" << endl;
	cout << "2 to lend a book" << endl;
	cout << "3 to display your books" << endl;
	cout << "4 to return borrowed book" << endl;
	cout << "5 to display Borrwed Book Details" << endl;
	cout << "0 to exit" << endl;
}

int main()
{
	LibraryAccountant accountant("AC1", "AC@123", 1234);
	accountant.displayLibraryName();
	accountant.addRack();

	LibraryMember member("Member1", "Mem@123", 1234);
	for (int i = 0; i < 6; i++)
	{
		accountant.addBookToLobrary("Avenged", "Shathish", "Horror");
		accountant.addBookToLobrary("Seven", "Dinesh", "Horror");
	}
	
	
	int input = -1;
	do
	{
		displayOptions();
		cin >> input;
		switch (input)
		{
			case 1:
			{
				accountant.displayBooks(member);
				break;
			}

			case 2:
			{
				cout << "enter book id" << endl;
				int bookID; cin >> bookID;
				accountant.lendBookToLibraryMember(&member, bookID);
				break;
			}

			case 3:
			{
				member.displayBorrowedBooks();
				break;
			}

			case 4:
			{
				cout << "Enter the book id you want to return" << endl;
				int bookID; cin >> bookID;
				accountant.returnBookFromLibraryMember(&member, bookID);
				break;
			}

			case 5:
			{
				accountant.showBorrowedBookDetails();
				break;
			}
		}

	} while (input!=0);
}