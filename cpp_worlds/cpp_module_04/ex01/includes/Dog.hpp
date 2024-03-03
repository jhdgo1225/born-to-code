#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog& rhs);
    Dog& operator=(const Dog& rhs);
    virtual         ~Dog();
    virtual void    makeSound() const;
    void            addIdeas(const std::string idea);
    void            showIdeas();
private:
    Brain   *brain;
    int     idx;
};

#endif
