#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP
# include "AForm.hpp"

class   PresidentialPardonForm: public AForm
{
public:
    PresidentialPardonForm(std::string name);
    PresidentialPardonForm(const PresidentialPardonForm& rhs);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
    virtual         ~PresidentialPardonForm();
    virtual void    execute(Bureaucrat const& executor) const;
};

#endif
