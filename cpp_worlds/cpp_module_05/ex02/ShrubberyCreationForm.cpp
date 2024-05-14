#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
    :AForm(name, 0, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
    :AForm(rhs)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    AForm::operator=(rhs);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (getSign() && getExecGrade() >= executor.getGrade())
    {
        std::string newFile = executor.getName().append("_shrubbery");
        std::ofstream writeFile(newFile.c_str());
        if (!writeFile.is_open())
        {
            std::cout << "Writefile Open Error\n";
            return ;
        }
        writeFile << "              v .   ._, |_  .," << '\n';
        writeFile << "           `-._\\/  .  \\ /    |/_" << '\n';
        writeFile << "               \\\\  _\\, y | \\//" << '\n';
        writeFile << "         _\\_.___\\\\, \\\\/ -.\\||" << '\n';
        writeFile << "           `7-,--.`._||  / / ," << '\n';
        writeFile << "           /'     `-. `./ / |/_.'" << '\n';
        writeFile << "                     |    |//" << '\n';
        writeFile << "                     |_    /" << '\n';
        writeFile << "                     |-   |" << '\n';
        writeFile << "                     |   =|" << '\n';
        writeFile << "                     |    |" << '\n';
        writeFile << "--------------------/ ,  . \\--------._" << '\n';
        writeFile.close();
        std::cout << executor.getName() << " plants a shrubbery tree" << '\n';
    }
    else if (!getSign())
        throw NotSignedException(executor.getName(), getFormName());
    else
        throw BureaucratGradeTooLowThanFormGradeException(executor.getName(), "execute", getFormName(), executor.getGrade(), getExecGrade());
}
