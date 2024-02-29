#include "Dog.hpp"
#include <cstdlib>

Dog::Dog()
    :Animal("Dog"),
     idx(0)
{
    try {
        std::cout << "\033[1;32m" << "<< Dog Class is Created >>" << "\033[0m" << '\n';
        brain = new Brain();
    } catch (std::bad_alloc& exception) {
        std::cout << "exception : " << exception.what() << '\n';
        std::abort();
    }
}

Dog::~Dog()
{
    std::cout << "\033[1;31m" << "<< Dog Class is Destroyed >>" << "\033[0m" << '\n';
    delete brain;
}

Dog::Dog(const Dog& rhs)
    :Animal(rhs.type),
     idx(rhs.idx)
{
    try {
        std::cout << "\033[1;32m" << "<< Dog Class is Created >>" << "\033[0m" << '\n';
        brain = new Brain(*rhs.brain);
    } catch (std::bad_alloc& exception) {
        std::cout << "exception : " << exception.what() << '\n';
        std::abort();
    }
}

Dog& Dog::operator=(const Dog& rhs)
{
    type = rhs.type;
    *brain = *rhs.brain;
    return *this;
}

void    Dog::makeSound()
{
    std::cout << "Dog " << type << " Meong!Meong! 🐶" << '\n';
}

void    Dog::addIdeas(const std::string idea)
{
    brain->setIdea(idea, idx++);
}

void    Dog::showIdeas()
{
    std::cout << "[ Show " << type << "'s Ideas ]" << '\n';
    for (int i=0; i<idx; i++)
        std::cout << brain->getIdea(i) << '\n';
    std::cout << '\n';
}
