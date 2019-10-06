#include <iostream>
#include "../Library/Library.cpp"
#include "../LibraryMembers/LibraryAccountant.cpp"
using namespace std;

int main()
{
	LibraryAccountant accountant("AC1", "AC@123", 1234);
	accountant.displayLibraryName();

	LibraryMember member("Member1", "Mem@123", 1234);
	accountant.tryaddBook(member, "Avenged", "Shathish", "Horror");
	accountant.tryaddBook(member, "Seven", "Dinesh", "Horror");
	
	int input = -1;
	do
	{
		cout << "1 to display books at library"<<endl;
		cout << "2 to lend a book" << endl;
		cout << "3 to display your books" << endl;
		cout << "0 to exit" << endl;
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
		}

	} while (input!=0);
}