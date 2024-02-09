#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	void	addNewContact(std::string& firstName, std::string& lastName, std::string& phoneNumber
							, std::string& nickname, std::string& secret);
	void	displayContactInfo();

private:
	Contact contacts[8];
	int		count;
};
#endif
