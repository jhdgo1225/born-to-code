#include "AForm.hpp"
#include <sstream>

AForm::GradeTooHighException::GradeTooHighException(std::string name, std::string thing, int grade)
{
    std::stringstream ss;
    ss << grade;
    message.append("[Form] \"").append(name).append("\"'s ").append(thing).append(" Grade (").append(ss.str()).append(") is too high. [Available: 1-150]");
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
    message.append("[Form] \"").append(name).append("\"'s ").append(thing).append(" Grade (").append(ss.str()).append(") is too low. [Available: 1-150]");
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char *AForm::GradeTooLowException::what()
{
    return (message.c_str());
}

AForm::BureaucratGradeTooLowThanFormGradeException::BureaucratGradeTooLowThanFormGradeException(std::string target, std::string thing, std::string frmName, int targetGrade, int formGrade)
{
    std::stringstream tgGrade;
    std::stringstream frmGrade;
    tgGrade << targetGrade;
    frmGrade << formGrade;
    message.append("[Bureaucrat] \"").append(target).append("\"'s ").append(thing).append(" grade is too lower than [Form] \"").append(frmName).append("\"\n");
    message.append("[Bureaucrat] grade => \"").append(tgGrade.str()).append("\", [Form] ").append(thing).append(" grade => \"").append(frmGrade.str()).append("\"");
}

AForm::BureaucratGradeTooLowThanFormGradeException::~BureaucratGradeTooLowThanFormGradeException() throw()
{
}

const char *AForm::BureaucratGradeTooLowThanFormGradeException::what()
{
    return (message.c_str());
}

AForm::NotSignedException::NotSignedException(std::string target, std::string frmName)
{
    message.append("[Bureaucrat] \"]").append(target).append("\" can't execute the [Form] \"").append(frmName).append("\"\n");
    message.append("The form is not signed");
}

AForm::NotSignedException::~NotSignedException() throw()
{
}

const char *AForm::NotSignedException::what()
{
    return (message.c_str());
}

AForm::AForm(std::string name, bool sign, int signGrade, int execGrade)
    :formName(name),
     sign(sign),
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

AForm::~AForm()
{
}

AForm::AForm(const AForm& rhs)
    :formName(rhs.formName),
     sign(rhs.sign),
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

AForm& AForm::operator=(const AForm& rhs)
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

std::string AForm::getFormName() const
{
    return (formName);
}

bool AForm::getSign() const
{
    return (sign);
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
        sign = true;
    else
        throw (GradeTooLowException(formName, "signing", signGrade));
}

std::ostream& operator<<(std::ostream& outputStream, const AForm& val)
{
    outputStream << "[AForm - \"" << val.getFormName() << "\", Status - " << val.getSign() << "] " << "Sign Grade : " << val.getSignGrade() << ", Execute Grade : " << val.getExecGrade();
    return (outputStream);
}
