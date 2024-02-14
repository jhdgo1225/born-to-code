#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>
#include <cstdio>

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	bool	addNewContact(void);
	void	displayContactInfo(void);

private:
	Contact contacts[8];
	int		count;
	bool	validateContactInfo(std::string& firstName, std::string& lastName, std::string& nickname
									, std::string& phoneNumber, std::string& secret);
	bool	validateDuplicatedPhoneNumber(std::string phoneNumber);
};

void	ftGetline(std::string str1, std::string &str2);

#endif
