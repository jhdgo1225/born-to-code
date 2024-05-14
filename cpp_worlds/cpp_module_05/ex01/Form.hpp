#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class   Bureaucrat;

class   Form
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
    Form(std::string name, bool sign, int signGrade, int execGrade);
    Form(const Form& rhs);
    Form& operator=(const Form& rhs);
    ~Form();
    std::string         getFormName() const;
    bool                getSign() const;
    int                 getSignGrade() const;
    int                 getExecGrade() const;
    void                beSigned(const Bureaucrat& target);
private:
    const std::string   formName;
    bool                sign;
    const int           signGrade;
    const int           execGrade;
};

std::ostream& operator<<(std::ostream& outputStream, const Form& val);

#endif
