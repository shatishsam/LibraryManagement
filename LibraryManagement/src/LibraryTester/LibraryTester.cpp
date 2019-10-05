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

	accountant.displayBooks(member);
	accountant.getCategoryBook(member, "Horror");
}