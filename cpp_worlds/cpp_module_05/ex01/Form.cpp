#include "Form.hpp"
#include <sstream>

Form::GradeTooHighException::GradeTooHighException(std::string name, std::string thing, int grade)
{
    std::stringstream ss;
    ss << grade;
    message.append("[Form] \"").append(name).append("\"'s ").append(thing).append(" Grade (").append(ss.str()).append(") is too high. [Available: 1-150]");
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char *Form::GradeTooHighException::what()
{
    return (message.c_str());
}

Form::GradeTooLowException::GradeTooLowException(std::string name, std::string thing, int grade)
{
    std::stringstream ss;
    ss << grade;
    message.append("[Form] \"").append(name).append("\"'s ").append(thing).append(" Grade (").append(ss.str()).append(") is too low. [Available: 1-150]");
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char *Form::GradeTooLowException::what()
{
    return (message.c_str());
}

Form::Form(std::string name, bool isSigned, int signGrade, int execGrade)
    :formName(name),
     isSigned(isSigned),
     signGrade(signGrade),
     execGrade(execGrade)
{
    if (signGrade <= 0)
        throw (GradeTooHighException(formName, "signing", signGrade));
    else if (signGrade > 150)
        throw (GradeTooLowException(formName, "signing", signGrade));
    if (execGrade <= 0)
        throw (GradeTooHighException(formName, "executing", execGrade));
    else if (execGrade > 150)
        throw (GradeTooLowException(formName, "executing", execGrade));
}

Form::~Form()
{
}

Form::Form(const Form& rhs)
    :formName(rhs.formName),
     isSigned(rhs.isSigned),
     signGrade(rhs.signGrade),
     execGrade(rhs.execGrade)
{
    if (signGrade <= 0)
        throw (GradeTooHighException(formName, "signing", signGrade));
    else if (signGrade > 150)
        throw (GradeTooLowException(formName, "signing", signGrade));
    if (execGrade <= 0)
        throw (GradeTooHighException(formName, "executing", execGrade));
    else if (execGrade > 150)
        throw (GradeTooLowException(formName, "executing", execGrade));
}

Form& Form::operator=(const Form& rhs)
{
    std::string *noConstFormName = const_cast<std::string *>(&formName);
    int *noConstSignGrade = const_cast<int *>(&signGrade);
    int *noConstExecGrade = const_cast<int *>(&execGrade);
    *noConstFormName = rhs.formName;
    *noConstSignGrade = rhs.signGrade;
    *noConstExecGrade = rhs.execGrade;
    if (signGrade <= 0)
        throw (GradeTooHighException(formName, "signing", signGrade));
    else if (signGrade > 150)
        throw (GradeTooLowException(formName, "signing", signGrade));
    if (execGrade <= 0)
        throw (GradeTooHighException(formName, "executing", execGrade));
    else if (execGrade > 150)
        throw (GradeTooLowException(formName, "executing", execGrade));
    return (*this);
}

std::string Form::getFormName() const
{
    return (formName);
}

bool Form::getIsSigned() const
{
    return (isSigned);
}

int Form::getSignGrade() const
{
    return (signGrade);
}

int Form::getExecGrade() const
{
    return (execGrade);
}

void    Form::beSigned(const Bureaucrat& target)
{
    if (signGrade >= target.getGrade())
        isSigned = true;
    else
        throw (GradeTooLowException(formName, "signing", signGrade));
}

std::ostream& operator<<(std::ostream& outputStream, const Form& val)
{
    outputStream << "[Form - \"" << val.getFormName() << "\", Status - " << val.getIsSigned() << "] " << "Sign Grade : " << val.getSignGrade() << ", Execute Grade : " << val.getExecGrade();
    return (outputStream);
}
