#ifndef DOG_HPP
# define DOG_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
public:
    Dog();
    Dog(const Dog& rhs);
    Dog& operator=(const Dog& rhs);
    virtual         ~Dog();
    virtual void    makeSound();
    void            addIdeas(const std::string idea);
    void            showIdeas();
private:
    Brain   *brain;
    int     idx;
};

#endif
