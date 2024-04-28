#include "Bureaucrat.hpp"
#include <sstream>

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string name, int grade)
{
    std::stringstream ss;
    ss << grade;
    message.append("[Bureaucrat] \"").append(name).append("\"'s Grade ").append(ss.str()).append(" is too high.");
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char *Bureaucrat::GradeTooHighException::what()
{
    return (message.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string name, int grade)
{
    std::stringstream ss;
    ss << grade;
    message.append("[Bureaucrat] \"").append(name).append("\"'s Grade ").append(ss.str()).append(" is too low.");
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char *Bureaucrat::GradeTooLowException::what()
{
    return (message.c_str());
}

Bureaucrat::Bureaucrat(std::string name, int grade)
    :name(name),
     grade(grade)
{
    if (grade <= 0)
        throw (GradeTooHighException(name, grade));
    else if (grade > 150)
        throw (GradeTooLowException(name, grade));
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs)
    :name(rhs.name),
     grade(rhs.grade)
{
    if (grade <= 0)
        throw (GradeTooHighException(name, grade));
    else if (grade > 150)
        throw (GradeTooLowException(name, grade));
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    std::string *ptr = const_cast<std::string *>(&name);
    *ptr = rhs.name;
    grade = rhs.grade;
    if (grade <= 0)
        throw (GradeTooHighException(name, grade));
    else if (grade > 150)
        throw (GradeTooLowException(name, grade));
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName(void) const
{
    return (name);
}

int Bureaucrat::getGrade(void) const
{
    return (grade);
}

void    Bureaucrat::increaseGrade(void)
{
    int check = grade - 1;
    if (check <= 0)
        throw (GradeTooHighException(name, check));
    grade = check;
}

void    Bureaucrat::decreaseGrade(void)
{
    int check = grade + 1;
    if (check > 150)
        throw (GradeTooLowException(name, check));
    grade = check;
}

void    Bureaucrat::signForm(Form& target)
{
    std::string reason;
    if (target.getIsSigned())
        reason = "the form was already signed";
    else if (grade > target.getSignGrade())
        reason = "you have a low level to sign the form.";
    if (target.getIsSigned() || grade > target.getSignGrade())
    {
        std::cout << "[Bureaucrat] - \"" << name << "\" couldn't sign [Form] - \"" << target.getFormName() << "\" ";
        std::cout << "because " << reason << '\n';
    }
    else
    {
        target.beSigned(*this);
        std::cout << "[Bureaucrat] - \"" << name << "\" signed [Form] - \"" << target.getFormName() << "\"" << '\n';
    }
}

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& val)
{
    outputStream << val.getName() << ", bureaucrat grade " << val.getGrade();
    return (outputStream);
}
