#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
    :value(0)
{
    std::cout << "\033[1;32m" << "Default constructor called" << "\033[0m" << '\n';
}

Fixed::Fixed(const int integer)
    :value(integer << fractionalBits)
{
    std::cout << "\033[1;32m" << "Int constructor called" << "\033[0m" << '\n';
}

Fixed::Fixed(const float decimal)
    :value((int)roundf(decimal * (1 << fractionalBits)))
{
    std::cout << "\033[1;32m" << "Float constructor called" << "\033[0m" << '\n';
}

Fixed::~Fixed()
{
    std::cout << value << '\n';
    std::cout << "\033[1;31m" << "Destructor called" << "\033[0m" << '\n';
}

Fixed::Fixed(const Fixed& fixed)
    :value(fixed.value)
{
    std::cout << "\033[1;32m" << "Copy constructor called" << "\033[0m" << '\n';
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    value = fixed.value;
    std::cout << "\033[1;32m" << "Copy assignment operator called" << "\033[0m" << '\n';
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
    int ret = value >> fractionalBits;
    return (ret + (ret < 0 && (value & 0b11111111)));
}

float Fixed::toFloat(void) const
{
    float   ret = (float)value / 256;
    return (ret);
}

std::ostream& operator<<(std::ostream& outputStream, const Fixed& val)
{
    outputStream << val.toFloat();
    return (outputStream);
}
