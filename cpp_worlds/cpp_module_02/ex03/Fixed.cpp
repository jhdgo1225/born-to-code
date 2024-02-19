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

bool Fixed::operator>(const Fixed& a) const
{
    return (this->toFloat() > a.toFloat());
}

bool Fixed::operator<(const Fixed& a) const
{
    return (this->toFloat() < a.toFloat());
}

bool Fixed::operator>=(const Fixed& a) const
{
    return (this->toFloat() >= a.toFloat());
}

bool Fixed::operator<=(const Fixed& a) const
{
    return (this->toFloat() <= a.toFloat());
}

bool Fixed::operator==(const Fixed& a) const
{
    return (this->toFloat() == a.toFloat());
}

bool Fixed::operator!=(const Fixed& a) const
{
    return (this->toFloat() != a.toFloat());
}

Fixed Fixed::operator+(const Fixed& a) const
{
    return (Fixed(this->toFloat() + a.toFloat()));
}

Fixed Fixed::operator-(const Fixed& a) const
{
    return (Fixed(this->toFloat() - a.toFloat()));
}

Fixed Fixed::operator*(const Fixed& a) const
{
    return (Fixed(this->toFloat() * a.toFloat()));
}

Fixed Fixed::operator/(const Fixed& a) const
{
    return (Fixed(this->toFloat() / a.toFloat()));
}

Fixed& Fixed::operator++(void)
{
    this->value = this->value + 256;
    return (*this);
}

Fixed& Fixed::operator--(void)
{
    this->value = this->value - 256;
    return (*this);
}

Fixed Fixed::operator++(int _val)
{
    (void)_val;
    Fixed tmp(*this);
    this->value = this->value + 256;
    return (tmp);
}

Fixed Fixed::operator--(int _val)
{
    (void)_val;
    Fixed tmp(*this);
    this->value = this->value - 256;
    return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return ((a.toFloat() < b.toFloat()) ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return ((a.toFloat() < b.toFloat()) ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return ((a.toFloat() > b.toFloat()) ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return ((a.toFloat() > b.toFloat()) ? a : b);
}

std::ostream& operator<<(std::ostream& outputStream, const Fixed& val)
{
    outputStream << val.toFloat();
    return (outputStream);
}
