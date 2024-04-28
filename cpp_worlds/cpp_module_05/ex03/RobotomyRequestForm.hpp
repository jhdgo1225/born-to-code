#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP
# include "AForm.hpp"

class   RobotomyRequestForm: public AForm
{
public:
    RobotomyRequestForm(std::string name);
    RobotomyRequestForm(const RobotomyRequestForm& rhs);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
    virtual         ~RobotomyRequestForm();
    virtual void    execute(Bureaucrat const& executor) const;
};

#endif
