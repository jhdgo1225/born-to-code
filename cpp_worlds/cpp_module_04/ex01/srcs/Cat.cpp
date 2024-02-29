#include "Cat.hpp"
#include <cstdlib>

Cat::Cat()
    :Animal("Cat"),
     idx(0)
{
    try {
        std::cout << "\033[1;32m" << "<< Cat Class is Created >>" << "\033[0m" << '\n';
        brain = new Brain();
    } catch (std::bad_alloc& exception) {
        std::cout << "exception : " << exception.what() << '\n';
        std::abort();
    }
}

Cat::~Cat()
{
    std::cout << "\033[1;31m" << "<< Cat Class is Destroyed >>" << "\033[0m" << '\n';
    delete brain;
}

Cat::Cat(const Cat& rhs)
    :Animal(rhs.type),
     idx(rhs.idx)
{
    try {
        std::cout << "\033[1;32m" << "<< Cat Class is Created >>" << "\033[0m" << '\n';
        brain = new Brain(*rhs.brain);
    } catch (std::bad_alloc& exception) {
        std::cout << "exception : " << exception.what() << '\n';
        std::abort();
    }
}

Cat& Cat::operator=(const Cat& rhs)
{
    type = rhs.type;
    idx = rhs.idx;
    *brain = *rhs.brain;
    return *this;
}

void    Cat::makeSound()
{
    std::cout << "Cat " << type  << " Meow~~ 🐱" << '\n';
}

void    Cat::addIdeas(const std::string idea)
{
    brain->setIdea(idea, idx++);
}

void    Cat::showIdeas()
{
    std::cout << "[ Show " << type << "'s Ideas ]" << '\n';
    for (int i=0; i<idx; i++)
        std::cout << brain->getIdea(i) << '\n';
    std::cout << '\n';
}
