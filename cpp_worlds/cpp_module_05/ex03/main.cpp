#include "Intern.hpp"

int main(void)
{
    try {
        Intern someRandomIntern;
        AForm *rrf;
        AForm *rrf2;
        AForm *rrf3;

        rrf = someRandomIntern.makeForm("shrubbery creation", "MyLimeOrangeTree");
        std::cout << *rrf << '\n';

        rrf2 = someRandomIntern.makeForm("robotomy request", "robot1597");
        std::cout << *rrf2 << '\n';

        rrf3 = someRandomIntern.makeForm("presidential parden", "I'm President");
        std::cout << *rrf3 << '\n';
        delete rrf;
        delete rrf2;
        delete rrf3;
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
    } catch (Intern::UnknownFormError& e) {
        std::cout << e.what() << '\n';
    }
    return (0);
}
