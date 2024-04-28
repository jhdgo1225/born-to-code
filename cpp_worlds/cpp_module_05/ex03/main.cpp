#include "Intern.hpp"

int main(void)
{
    Intern someRandomIntern;
    AForm *rrf;

    rrf = someRandomIntern.makeForm("shrubbery creation", "MyLimeOrangeTree");
    std::cout << *rrf << '\n';
    return (0);
}
