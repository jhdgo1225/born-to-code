#include "Fixed.hpp"

Fixed::Fixed()
    :value(0)
{
    std::cout << "Default constructor called" << '\n';
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << '\n';
}

Fixed::Fixed(const Fixed& fixed)
    :value(fixed.value)
{
    std::cout << "Copy constructor called" << '\n';
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    value = fixed.value;
    std::cout << "Copy assignment operator called" << '\n';
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << '\n';
    return (value);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << '\n';
    value = raw;
}
