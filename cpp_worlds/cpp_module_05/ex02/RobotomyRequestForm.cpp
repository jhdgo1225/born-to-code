#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string name)
    :AForm(name, 0, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
    :AForm(rhs)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    AForm::operator=(rhs);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (getSign() && getExecGrade() >= executor.getGrade())
    {
        srand(static_cast<unsigned>(time(NULL)));
        int randNum = rand() % 100;
        if (randNum < 50)
            std::cout << executor.getName() << " has been robotomized successfully!" << '\n';
        else
            std::cout << executor.getName() << " was failed to Robotomize..." << '\n';
    }
    else if (!getSign())
        throw NotSignedException(executor.getName(), getFormName());
    else
        throw BureaucratGradeTooLowThanFormGradeException(executor.getName(), "execute", getFormName(), executor.getGrade(), getExecGrade());
}
