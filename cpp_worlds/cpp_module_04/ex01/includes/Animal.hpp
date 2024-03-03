#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
public:
    Animal();
    Animal(const Animal& rhs);
    Animal& operator=(const Animal& rhs);
    virtual         ~Animal();
    virtual void    makeSound() const;

protected:
    std::string type;
    Animal(const std::string type);
};

#endif
