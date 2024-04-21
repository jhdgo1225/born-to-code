#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try {
        Bureaucrat p1("jongho", 149);
        std::cout << p1 << '\n';
        Bureaucrat p2("jonghopark", 11);
        std::cout << p2 << '\n';
        Bureaucrat p3("her", 1);
        std::cout << p3 << '\n';
        Bureaucrat p4("him", 150);
        std::cout << p4 << '\n';
        
        Form f1("normal form", false, 50, 40);
        Form f2("secret form", false, 1, 1);
        p1.signForm(f1);
        p2.signForm(f1);
        p3.signForm(f1);
        p4.signForm(f2);
        p3.signForm(f2);
        Form f3(f1);
        std::cout << f3 << '\n';
        f3 = f2;
        std::cout << f3 << '\n';
    } catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << '\n';
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << '\n';
    } catch (Form::GradeTooHighException& e) {
        std::cout << e.what() << '\n';
    } catch (Form::GradeTooLowException& e) {
        std::cout << e.what() << '\n';
    }
}
