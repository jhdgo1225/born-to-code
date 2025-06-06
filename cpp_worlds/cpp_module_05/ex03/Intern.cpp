#include "Intern.hpp"
#include <cstdlib>

Intern::UnknownFormError::UnknownFormError(std::string name)
{
    message.append("[Form] \"").append(name).append("\" is Unknown Form Category.");
}

Intern::UnknownFormError::~UnknownFormError() throw()
{
}

const char *Intern::UnknownFormError::what()
{
    return (message.c_str());
}

Intern::Intern()
{
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(const std::string form, const std::string target)
{
    try {
        const std::string threeForms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
        int idx = 0;
        while (idx < 3)
        {
            if (!form.compare(threeForms[idx]))
                break;
            idx++;
        }
        AForm *ret;
        switch(idx)
        {
            case 0:
                ret = new ShrubberyCreationForm(target);
                break ;
            case 1:
                ret = new RobotomyRequestForm(target);
                break ;
            case 2:
                ret = new PresidentialPardonForm(target);
                break ;
            default:
                ret = NULL;
        }
        if (ret)
            std::cout << "Intern creates " << form << '\n';
        else
        {
            std::cout << form << " is undefined form" << '\n';
            throw UnknownFormError(form);
        }
        return (ret);
    } catch (std::bad_alloc &exception) {
        std::cout << "exception : " << exception.what() << '\n';
        std::abort();
    }
    return (NULL);
}
