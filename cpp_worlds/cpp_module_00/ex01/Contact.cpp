#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::setFirstName(std::string& firstName)
{
	this->firstName = firstName;
}

void	Contact::setLastName(std::string& lastName)
{
	this->lastName = lastName;
}

void	Contact::setNickname(std::string& nickname)
{
	this->nickname = nickname;
}

void	Contact::setPhoneNumber(std::string& phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void	Contact::setSecret(std::string& secret)
{
	this->secret = secret;
}

std::string	Contact::getFirstName(void)
{
	return (firstName);
}

std::string	Contact::getLastName(void)
{
	return (lastName);
}

std::string	Contact::getNickname(void)
{
	return (nickname);
}

std::string	Contact::getPhoneNumber(void)
{
	return (phoneNumber);
}

std::string	Contact::getSecret(void)
{
	return (secret);
}

