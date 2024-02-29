#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>

class AAnimal
{
public:
    AAnimal();
    AAnimal(const AAnimal& rhs);
    AAnimal& operator=(const AAnimal& rhs);
    virtual         ~AAnimal();
    virtual void    makeSound() = 0;

protected:
    std::string type;
    AAnimal(const std::string type);
};

#endif
