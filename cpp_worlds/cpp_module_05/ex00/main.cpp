#include "Bureaucrat.hpp"

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
        // p3.increaseGrade();
        // p4.decreaseGrade();
        p1 = p3;
        std::cout << p1 << '\n';
        Bureaucrat p5(p2);
        std::cout << p5 << '\n';
    } catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << '\n';
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << '\n';
    }
}
