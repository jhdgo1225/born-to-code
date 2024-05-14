#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name)
    :AForm(name, 0, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs)
    :AForm(rhs)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    AForm::operator=(rhs);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (getSign() && getExecGrade() >= executor.getGrade())
        std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox" << '\n';
    else if (!getSign())
        throw NotSignedException(executor.getName(), getFormName());
    else
        throw BureaucratGradeTooLowThanFormGradeException(executor.getName(), "execute", getFormName(), executor.getGrade(), getExecGrade());
}
