#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include "AForm.hpp"

class   AForm;

class   Bureaucrat
{
public:
    class   GradeTooHighException: public std::exception {
        private:
            std::string message;
        public:
            GradeTooHighException(const std::string name, int grade);
            virtual ~GradeTooHighException() throw();
            const char *what();
    };
    class   GradeTooLowException: public std::exception {
        private:
            std::string message;
        public:
            GradeTooLowException(const std::string name, int grade);
            virtual ~GradeTooLowException() throw();
            const char *what();
    };
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& rhs);
    Bureaucrat& operator=(const Bureaucrat& rhs);
    ~Bureaucrat();
    std::string         getName() const;
    int                 getGrade() const;
    void                increaseGrade();
    void                decreaseGrade();
    void                signForm(AForm& target);
    void                executeForm(AForm const& form);

private:
    const std::string   name;
    int                 grade;
};

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& val);

#endif
