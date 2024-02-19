#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
    :value(0)
{
    std::cout << "Default constructor called" << '\n';
}

Fixed::Fixed(const int integer)
    :value(integer << fractionalBits)
{
    std::cout << "Int constructor called" << '\n';
}

Fixed::Fixed(const float decimal)
    :value((int)roundf(decimal * 256))
{
    std::cout << "Float constructor called" << '\n';
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

int Fixed::toInt(void) const
{
    return (value >> fractionalBits);
}

float Fixed::toFloat(void) const
{
    return ((float)value / 256);
}

std::ostream& operator<<(std::ostream& outputStream, const Fixed& val)
{
    outputStream << val.toFloat();
    return (outputStream);
}
