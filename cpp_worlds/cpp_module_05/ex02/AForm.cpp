#include "AForm.hpp"
#include <sstream>

AForm::GradeTooHighException::GradeTooHighException(std::string name, std::string thing, int grade)
{
    std::stringstream ss;
    ss << grade;
    message.append(name).append("'s ").append(thing).append(" Grade ").append(ss.str()).append(" is too high.");
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char *AForm::GradeTooHighException::what()
{
    return (message.c_str());
}

AForm::GradeTooLowException::GradeTooLowException(std::string name, std::string thing, int grade)
{
    std::stringstream ss;
    ss << grade;
    message.append(name).append("'s ").append(thing).append(" Grade ").append(ss.str()).append(" is too low.");
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char *AForm::GradeTooLowException::what()
{
    return (message.c_str());
}

AForm::AForm(std::string name, bool isSigned, int signGrade, int execGrade)
    :AformName(name),
     isSigned(isSigned),
     signGrade(signGrade),
     execGrade(execGrade)
{
    if (signGrade <= 0)
        throw (GradeTooHighException(AformName, "signing", signGrade));
    else if (signGrade > 150)
        throw (GradeTooLowException(AformName, "signing", signGrade));
    if (execGrade <= 0)
        throw (GradeTooHighException(AformName, "executing", execGrade));
    else if (execGrade > 150)
        throw (GradeTooLowException(AformName, "executing", execGrade));
}

AForm::~AForm()
{
}

AForm::AForm(const AForm& rhs)
    :AformName(rhs.AformName),
     isSigned(rhs.isSigned),
     signGrade(rhs.signGrade),
     execGrade(rhs.execGrade)
{
    if (signGrade <= 0)
        throw (GradeTooHighException(AformName, "signing", signGrade));
    else if (signGrade > 150)
        throw (GradeTooLowException(AformName, "signing", signGrade));
    if (execGrade <= 0)
        throw (GradeTooHighException(AformName, "executing", execGrade));
    else if (execGrade > 150)
        throw (GradeTooLowException(AformName, "executing", execGrade));
}

AForm& AForm::operator=(const AForm& rhs)
{
    std::string *noConstAFormName = const_cast<std::string *>(&AformName);
    int *noConstSignGrade = const_cast<int *>(&signGrade);
    int *noConstExecGrade = const_cast<int *>(&execGrade);
    *noConstAFormName = rhs.AformName;
    *noConstSignGrade = rhs.signGrade;
    *noConstExecGrade = rhs.execGrade;
    if (signGrade <= 0)
        throw (GradeTooHighException(AformName, "signing", signGrade));
    else if (signGrade > 150)
        throw (GradeTooLowException(AformName, "signing", signGrade));
    if (execGrade <= 0)
        throw (GradeTooHighException(AformName, "executing", execGrade));
    else if (execGrade > 150)
        throw (GradeTooLowException(AformName, "executing", execGrade));
    return (*this);
}

std::string AForm::getAFormName() const
{
    return (AformName);
}

bool AForm::getIsSigned() const
{
    return (isSigned);
}

int AForm::getSignGrade() const
{
    return (signGrade);
}

int AForm::getExecGrade() const
{
    return (execGrade);
}

void    AForm::beSigned(const Bureaucrat& target)
{
    if (signGrade >= target.getGrade())
        isSigned = true;
    else
        throw (GradeTooLowException(AformName, "signing", signGrade));
}

std::ostream& operator<<(std::ostream& outputStream, const AForm& val)
{
    outputStream << "[AForm - \"" << val.getAFormName() << "\", Status - " << val.getIsSigned() << "] " << "Sign Grade : " << val.getSignGrade() << ", Execute Grade : " << val.getExecGrade();
    return (outputStream);
}
