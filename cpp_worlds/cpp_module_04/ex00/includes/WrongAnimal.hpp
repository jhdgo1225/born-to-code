#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& rhs);
    WrongAnimal& operator=(const WrongAnimal& rhs);
    virtual         ~WrongAnimal();
    void            makeSound() const;

protected:
    std::string type;
    WrongAnimal(const std::string type);
};

#endif
