#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP
# include "AForm.hpp"

class   ShrubberyCreationForm: public AForm
{
public:
    ShrubberyCreationForm(std::string name);
    ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
    virtual         ~ShrubberyCreationForm();
    virtual void    execute(Bureaucrat const& executor) const;
};

#endif
