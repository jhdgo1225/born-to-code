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
    bool operator>(const Fixed& a) const;
    bool operator<(const Fixed& a) const;
    bool operator>=(const Fixed& a) const;
    bool operator<=(const Fixed& a) const;
    bool operator==(const Fixed& a) const;
    bool operator!=(const Fixed& a) const;
    const Fixed operator+(const Fixed& a) const;
    const Fixed operator-(const Fixed& a) const;
    const Fixed operator*(const Fixed& a) const;
    const Fixed operator/(const Fixed& a) const;
    const Fixed& operator++(void);
    const Fixed& operator--(void);
    const Fixed operator++(int _val);
    const Fixed operator--(int _val);
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
private:
    int value;
    static const int fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& outputStream, const Fixed& val);

#endif
