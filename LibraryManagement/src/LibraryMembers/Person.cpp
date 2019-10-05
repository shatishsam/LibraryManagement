#pragma once

#include <iostream>
#include <string>
using std::cout; using std::endl;
class Person
{
private:
	std::string Name;
	std::string Email;
	int mobileNumber;

public:
	Person(std::string Name, std::string EMail, int mobileNumber)
	{
		this->Name = Name;
		this->Email = EMail;
		this->mobileNumber = mobileNumber;
	}

	//get name
	std::string getName() { return this->Name; }

	//get email
	std::string getEmail() { return this->Email; }

	//get mobile number
	int getMobileNumber() { return this->mobileNumber; }

	//display user details
	void displayPersonDetails()
	{
		cout << "Name is " << getName() << endl;
		cout << "EMail is " << getEmail() << endl;
		cout << "Mobile Number is" << getMobileNumber() << endl;
	}
};
