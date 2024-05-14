#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    try {
        Bureaucrat br1("GOD", 1);
        Bureaucrat br2("GODD", 5);
        Bureaucrat br3("GODDD", 5);
        AForm *f1 = new ShrubberyCreationForm("shrurururu");
        AForm *f2 = new RobotomyRequestForm("bobobobobot");
        AForm *f3 = new PresidentialPardonForm("pardon");
        br1.signForm(*f1);
        br1.executeForm(*f1);
        delete f1;
        delete f2;
        delete f3;
    } catch (std::bad_alloc& e) {
        std::cout << e.what() << '\n';
    } catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << '\n';
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << '\n';
    } catch (AForm::GradeTooHighException& e) {
        std::cout << e.what() << '\n';
    } catch (AForm::GradeTooLowException& e) {
        std::cout << e.what() << '\n';
    } catch (AForm::NotSignedException& e) {
        std::cout << e.what() << '\n';
    } catch (AForm::BureaucratGradeTooLowThanFormGradeException& e) {
        std::cout << e.what() << '\n';
    }
    return (0);
}
