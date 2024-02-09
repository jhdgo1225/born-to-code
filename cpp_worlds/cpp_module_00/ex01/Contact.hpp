#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact {
public:
	Contact();
	~Contact();
	void		setFirstName(std::string& firstName);
	void		setLastName(std::string& lastName);
	void		setNickname(std::string& nickname);
	void		setPhoneNumber(std::string& phoneNumber);
	void		setSecret(std::string& secret);
	std::string	getFirstName(void);
	std::string	getLastName(void);
	std::string	getNickname(void);
	std::string	getPhoneNumber(void);
	std::string	getSecret(void);

private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	secret;
};
#endif
