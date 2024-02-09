#include "PhoneBook.hpp"

void	ftGetline(std::string str1, std::string &str2)
{
	std::cout << str1 << ">> ";
	getline(std::cin, str2);
	if (std::cin.eof())
	{
		std::cin.clear();
		std::clearerr(stdin);
		std::cout << '\n';
	}
}

void inputContactInfo(std::string& firstName, std::string& lastName, std::string& nickname, std::string& phoneNumber, std::string& secret)
{
	system("clear");
	ftGetline("First Name ", firstName);
	ftGetline("Last Name ", lastName);
	ftGetline("Nickname ", nickname);
	ftGetline("Phone Number ", phoneNumber);
	ftGetline("Darkest Secret ", secret);
}

int	validateContactInfo(std::string& firstName, std::string& lastName, std::string& nickname, std::string& phoneNumber, std::string& secret)
{
	size_t i;

	// validate first name
	for (i=0; firstName[i]; i++)
	{
		if (i == 0)
		{
			if (!(firstName[i] >= 'A' && firstName[i] <= 'Z'))
				return (1);
		}
		else if (!(firstName[i] >= 'a' && firstName[i] <= 'z'))
			return (1);
	}
	if (i < 2)
		return (1);

	// validate last name
	for (i=0; lastName[i]; i++)
	{
		if (i == 0)
		{
			if (!(lastName[0] >= 'A' && lastName[0] <= 'Z'))
				return (1);
		}
		else if (!(lastName[i] >= 'a' && lastName[i] <= 'z'))
			return (1);
	}
	if (i < 2)
		return (1);

	// validate nick name, secret
	if (nickname.empty() || secret.empty())
		return (1);

	// validate phone number
	for (i=0; phoneNumber[i]; i++)
	{
		if (!(phoneNumber[i] >= '0' && phoneNumber[i] <= '9'))
			return (1);
	}
	if (i != 11)
		return (1);
	return (0);
}

void	printMenu(void)
{
	std::cout << "[The Light PhoneBook!]\n";
	std::cout << "Input One Of Following Commands\n";
	std::cout << "-----------------------------------\n";
	std::cout << "1. ADD\n";
	std::cout << "2. SEARCH\n";
	std::cout << "3. EXIT\n";
}

int	main(void)
{
	PhoneBook	book;
	std::string cmd;
	std::string	firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string secret;

	while (1)
	{
		system("clear");
		printMenu();
		ftGetline("", cmd);
		if (!cmd.compare("ADD"))
		{
			inputContactInfo(firstName, lastName, nickname, phoneNumber, secret);
			if (validateContactInfo(firstName, lastName, nickname, phoneNumber, secret))
			{
				std::cout << "Invalid Contact Information!\n";
				std::cout << "(Press Enter)\n";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.clear();
				std::clearerr(stdin);
				continue ;
			}
			book.addNewContact(firstName, lastName, nickname, phoneNumber, secret);
		}
		if (!cmd.compare("SEARCH"))
		{
			book.displayContactInfo();
		}
		if (!cmd.compare("EXIT"))
		{
			std::cout << "Bye!\n";
			return (0);
		}
	}
	return (0);
}
