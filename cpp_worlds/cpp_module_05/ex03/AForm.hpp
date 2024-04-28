#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class   Bureaucrat;

class   AForm
{
public:
    class   GradeTooHighException: public std::exception {
        private:
            std::string message;
        public:
            GradeTooHighException(std::string name, std::string thing, int grade);
            virtual ~GradeTooHighException() throw();
            const char *what();
    };
    class   GradeTooLowException: public std::exception {
        private:
            std::string message;
        public:
            GradeTooLowException(std::string name, std::string thing, int grade);
            virtual ~GradeTooLowException() throw();
            const char *what();
    };
    class   BureaucratGradeTooLowThanFormGradeException: public std::exception {
        private:
            std::string message;
        public:
            BureaucratGradeTooLowThanFormGradeException(std::string target, std::string thing, std::string frmName, int targetGrade, int formGrade);
            virtual ~BureaucratGradeTooLowThanFormGradeException() throw();
            const char *what();
    };
    class   NotSignedException: public std::exception {
        private:
            std::string message;
        public:
            NotSignedException(std::string target, std::string frmName);
            virtual ~NotSignedException() throw();
            const char *what();
    };
    AForm(std::string name, bool isSigned, int signGrade, int execGrade);
    AForm(const AForm& rhs);
    AForm& operator=(const AForm& rhs);
    virtual ~AForm();
    std::string         getFormName() const;
    bool                getIsSigned() const;
    int                 getSignGrade() const;
    int                 getExecGrade() const;
    void                beSigned(const Bureaucrat& target);
    virtual void        execute(Bureaucrat const& executor) const = 0;
private:
    const std::string   formName;
    bool                isSigned;
    const int           signGrade;
    const int           execGrade;
};

std::ostream& operator<<(std::ostream& outputStream, const AForm& val);

#endif
