#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class   Intern
{
public:
    class   UnknownFormError: public std::exception {
        private:
            std::string message;
        public:
            UnknownFormError(const std::string name);
            virtual ~UnknownFormError() throw();
            const char *what();
    };
    Intern();
    ~Intern();
    AForm *makeForm(const std::string form, const std::string target);
private:
    Intern(const Intern& rhs);
    Intern& operator=(const Intern& rhs);
};

#endif
