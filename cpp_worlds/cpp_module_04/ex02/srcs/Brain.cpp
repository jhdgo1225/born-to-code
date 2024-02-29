#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "\033[1;32m" << "<< Brain Class is Created >>" << "\033[0m" << '\n';
}

Brain::~Brain()
{
    std::cout << "\033[1;31m" << "<< Brain Class is Destroyed >>" << "\033[0m" << '\n';
}

Brain::Brain(const Brain& rhs)
{
    std::cout << "\033[1;32m" << "<< Brain Class is Created >>" << "\033[0m" << '\n';
    for (int i=0; i<100; i++)
        ideas[i] = rhs.ideas[i];
}

Brain& Brain::operator=(const Brain& rhs)
{
    for (int i=0; i<100; i++)
        ideas[i] = rhs.ideas[i];
    return *this;
}

void    Brain::setIdea(const std::string idea, int i)
{
    ideas[i] = idea;
}

std::string Brain::getIdea(int i)
{
    return (ideas[i]);
}
