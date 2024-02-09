#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook()
	: count(0)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addNewContact(std::string& firstName, std::string& lastName, std::string& nickname, std::string& phoneNumber, std::string& secret)
{
	contacts[count % 8].setFirstName(firstName);
	contacts[count % 8].setLastName(lastName);
	contacts[count % 8].setNickname(nickname);
	contacts[count % 8].setPhoneNumber(phoneNumber);
	contacts[count % 8].setSecret(secret);
	count++;
	if (count < 0)
		count = 8;
}

void PhoneBook::displayContactInfo()
{
	std::string index;
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	secret;

	if (!count)
	{
		std::cout << "No Contents in PhoneBook!\n";
		return ;
	}
	std::cout << std::setw(10) << "index";
	std::cout << '|';
	std::cout << std::setw(10) << "First Name";
	std::cout << '|';
	std::cout << std::setw(10) << "Last Name";
	std::cout << '|';
	std::cout << std::setw(10) << "Nickname";
	std::cout << '\n';
	for (int i=0; i<8; i++)
	{
		firstName = contacts[i].getFirstName();
		if (firstName.empty())
			break ;
		lastName = contacts[i].getLastName();
		nickname = contacts[i].getNickname();
		std::cout << std::setw(10) << i + 1;
		std::cout << '|';
		((firstName.size() > 10) ? std::cout << firstName.substr(0, 9) << "." : std::cout << std::setw(10) << firstName);
		std::cout << '|';
		((lastName.size() > 10) ? std::cout << lastName.substr(0, 9) << "." : std::cout << std::setw(10) << lastName);
		std::cout << '|';
		((nickname.size() > 10) ? std::cout << nickname.substr(0, 9) << "." : std::cout << std::setw(10) << nickname);
		std::cout << '\n';
	}
	std::clearerr(stdin);
	std::cout << "Input index>> ";
	getline(std::cin, index);
	if (std::cin.eof())
	{
		std::cin.clear();
		std::clearerr(stdin);
		std::cout << '\n';
	}
	if ((index.size() != 1 || !(index[0] >= '1' && index[0] <= '8'))
		|| contacts[index[0] - '1'].getFirstName().empty())
	{
		std::cout << "Invalid Index!\n";
		return ;
	}
	firstName = contacts[index[0] - '1'].getFirstName();
	lastName = contacts[index[0] - '1'].getLastName();
	nickname = contacts[index[0] - '1'].getNickname();
	phoneNumber = contacts[index[0] - '1'].getPhoneNumber();
	secret = contacts[index[0] - '1'].getSecret();
	std::cout << "============= More Information about " << index[0] - '0' << " =============\n";
	std::cout << "First Name : " << firstName << '\n';
	std::cout << "Last Name : " << lastName << '\n';
	std::cout << "Nickname : " << nickname << '\n';
	std::cout << "Phone Number : " << phoneNumber << '\n';
	std::cout << "Darkest Secret : " << secret << '\n';
	return ;
}
