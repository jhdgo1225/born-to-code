#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
    :value(0)
{
}

Fixed::Fixed(const int integer)
    :value(integer << fractionalBits)
{
}

Fixed::Fixed(const float decimal)
    :value((int)roundf(decimal * 256))
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed& fixed)
    :value(fixed.value)
{
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    value = fixed.value;
    return *this;
}

int Fixed::getRawBits(void) const
{
    return (value);
}

void    Fixed::setRawBits(int const raw)
{
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

const Fixed Fixed::operator+(const Fixed& a) const
{
    return (Fixed(this->toFloat() + a.toFloat()));
}

const Fixed Fixed::operator-(const Fixed& a) const
{
    return (Fixed(this->toFloat() - a.toFloat()));
}

const Fixed Fixed::operator*(const Fixed& a) const
{
    return (Fixed(this->toFloat() * a.toFloat()));
}

const Fixed Fixed::operator/(const Fixed& a) const
{
    return (Fixed(this->toFloat() / a.toFloat()));
}

const Fixed& Fixed::operator++(void)
{
    this->value = this->value + 1;
    return (*this);
}

const Fixed& Fixed::operator--(void)
{
    this->value = this->value - 1;
    return (*this);
}

const Fixed Fixed::operator++(int _val)
{
    (void)_val;
    Fixed tmp(*this);
    this->value = this->value + 1;
    return (tmp);
}

const Fixed Fixed::operator--(int _val)
{
    (void)_val;
    Fixed tmp(*this);
    this->value = this->value - 1;
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
