#include "PhoneBook.hpp"
#include <iomanip>

void	printSearchCmdScreen()
{
	std::cout << std::setw(10) << "index";
	std::cout << '|';
	std::cout << std::setw(10) << "First Name";
	std::cout << '|';
	std::cout << std::setw(10) << "Last Name";
	std::cout << '|';
	std::cout << std::setw(10) << "Nickname";
	std::cout << '\n';
}

void	printContactFieldInfo(std::string field, std::string sep)
{
	((field.size() > 10) ? std::cout << field.substr(0, 9) << "." : std::cout << std::setw(10) << field);
	std::cout << sep;
}

void	printOneContactInfo(int index, std::string& firstName, std::string& lastName
							, std::string& nickname, std::string& phoneNumber, std::string& secret)
{
	std::cout << "\033[1;32m" << "============= More Information about " << index << " =============" << "\033[0m" << '\n';
	std::cout << "First Name : " << firstName << '\n';
	std::cout << "Last Name : " << lastName << '\n';
	std::cout << "Nickname : " << nickname << '\n';
	std::cout << "Phone Number : " << phoneNumber << '\n';
	std::cout << "Darkest Secret : " << secret << '\n';
}

bool	inputIndex(std::string& index)
{
	ftGetline("Input index", index);
	if (index.size() != 1 || !(index[0] >= '1' && index[0] <= '8'))
	{
		std::cout << "\033[1;31m" << "Invalid Index!" << "\033[0m" << '\n';
		return (false);
	}
	return (true);
}

PhoneBook::PhoneBook()
	: count(0)
{
}

PhoneBook::~PhoneBook()
{
}

bool	PhoneBook::validateContactInfo(std::string& firstName, std::string& lastName, std::string& nickname, std::string& phoneNumber, std::string& secret)
{
	ftGetline("First Name ", firstName);
	ftGetline("Last Name ", lastName);
	ftGetline("Nickname ", nickname);
	ftGetline("Phone Number ", phoneNumber);
	ftGetline("Darkest Secret ", secret);
	
	size_t i;
	for (i=0; firstName[i]; i++)
	{
		if (i == 0)
		{
			if (!(firstName[i] >= 'A' && firstName[i] <= 'Z'))
				return (false);
		}
		else if (!(firstName[i] >= 'a' && firstName[i] <= 'z'))
			return (false);
	}
	if (i < 2)
		return (false);

	for (i=0; lastName[i]; i++)
	{
		if (i == 0)
		{
			if (!(lastName[0] >= 'A' && lastName[0] <= 'Z'))
				return (false);
		}
		else if (!(lastName[i] >= 'a' && lastName[i] <= 'z'))
			return (false);
	}
	if (i < 2)
		return (false);

	if (nickname.empty() || secret.empty())
		return (false);

	for (i=0; phoneNumber[i]; i++)
	{
		if (!(phoneNumber[i] >= '0' && phoneNumber[i] <= '9'))
			return (false);
	}
	if (i != 11)
		return (false);
	return (true);
}

bool	PhoneBook::validateDuplicatedPhoneNumber(std::string phoneNumber)
{
	for (size_t i=0; i < 8 && !contacts[i].getPhoneNumber().empty(); i++)
	{
		if (!phoneNumber.compare(contacts[i].getPhoneNumber()))
		{
			return (false);
		}
	}
	return (true);
}

bool PhoneBook::addNewContact()
{
	std::string	firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string secret;

	if (!validateContactInfo(firstName, lastName, nickname, phoneNumber, secret))
	{
		std::cout << "\033[1;31m" << "Invalid Contact Information!" << "\033[0m" << '\n';
		return (false);
	}
	if (!validateDuplicatedPhoneNumber(phoneNumber))
	{
		std::cout << "\033[1;31m" << "Duplicated Phone Number in PhoneBook" << "\033[0m" << '\n';
		return (false);
	}
	contacts[count % 8].setFirstName(firstName);
	contacts[count % 8].setLastName(lastName);
	contacts[count % 8].setNickname(nickname);
	contacts[count % 8].setPhoneNumber(phoneNumber);
	contacts[count % 8].setSecret(secret);
	count++;
	if (count < 0)
		count = 8;
	return (true);
}

void PhoneBook::displayContactInfo()
{
	if (!count)
	{
		std::cout << "\033[1;31m" << "No Contents in PhoneBook!" << "\033[0m" << '\n';
		return ;
	}
	printSearchCmdScreen();
	for (int i=0; i<8; i++)
	{
		if (contacts[i].getFirstName().empty())
			break ;
		std::cout << std::setw(10) << i + 1;
		std::cout << '|';
		printContactFieldInfo(contacts[i].getFirstName(), "|");
		printContactFieldInfo(contacts[i].getLastName(), "|");
		printContactFieldInfo(contacts[i].getNickname(), "\n");
	}
	std::string index;
	if (!inputIndex(index))
		return ;
	std::string	firstName = contacts[index[0] - '1'].getFirstName();
	if (firstName.empty())
	{
		std::cout << "\033[1;31m" << "Invalid Index!" << "\033[0m" << '\n';
		return ;
	}
	std::string	lastName = contacts[index[0] - '1'].getLastName();
	std::string	nickname = contacts[index[0] - '1'].getNickname();
	std::string	phoneNumber = contacts[index[0] - '1'].getPhoneNumber();
	std::string	secret = contacts[index[0] - '1'].getSecret();
	printOneContactInfo(index[0] - '0', firstName, lastName, nickname, phoneNumber, secret);
	return ;
}
