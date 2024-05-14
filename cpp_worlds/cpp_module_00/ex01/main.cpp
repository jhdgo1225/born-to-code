#include "PhoneBook.hpp"
#include <cstdlib>
#include <limits>

void	printMenu(void)
{
	std::cout << "-----------------------------------\n";
	std::cout << "Input One Of Following Commands\n";
	std::cout << "-----------------------------------\n";
	std::cout << "1. ADD\n";
	std::cout << "2. SEARCH\n";
	std::cout << "3. EXIT\n";
}

void	clearBuffer(void)
{
	std::cin.clear();
	std::clearerr(stdin);
	return ;
}

void	ftGetline(std::string str1, std::string &str2)
{
	std::cout << str1 << ">> ";
	getline(std::cin, str2);
	if (std::cin.eof())
	{
		clearBuffer();
		std::cout << '\n';
	}
}

int	main(void)
{
	PhoneBook	book;
	std::string cmd;

	while (1)
	{
		system("clear");
		clearBuffer();
		printMenu();
		ftGetline("", cmd);
		if (!cmd.compare("ADD"))
		{
			if (book.addNewContact())
				std::cout << "\033[1;32m" << "SUCCESS 😊" << "\033[0m" << '\n';
		}
		else if (!cmd.compare("SEARCH"))
		{
			book.displayContactInfo();
		}
		else if (!cmd.compare("EXIT"))
		{
			std::cout << "Bye!\n";
			break ;
		}
		else
		{
			std::cout << "\033[1;31m" << "Command Not Found!" << "\033[0m" << '\n';
		}
		std::cout << "(Press Anything Key)\n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return (0);
}
