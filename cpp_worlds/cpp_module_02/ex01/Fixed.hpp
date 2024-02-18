#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
public:
    Fixed();
    Fixed(const int integer);
    Fixed(const float decimal);
    Fixed(const Fixed& fixed);
    Fixed& operator=(const Fixed& fixed);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
private:
    int value;
    static const int fration = 8;
};

std::ostream& operator<<(std::ostream& outputStream, const Fixed& val);

#endif
