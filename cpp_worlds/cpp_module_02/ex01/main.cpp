#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed const b( 10 ); Fixed const c( -42.42f ); Fixed const d( b );
    a = Fixed( 1234.4321f );
    std::cout << '\n';

    std::cout << "\033[1;34m" << "Result of Fixed-Point Number" << "\033[0m" << '\n';
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << '\n';

    std::cout << "\033[1;34m" << "Storing into Integer of Each Fixed-Point Number" << "\033[0m" << '\n';
    std::cout << "The Integer Value of Fixed-Point number 'a' is " << a.getRawBits() << '\n';
    std::cout << "The Integer Value of Fixed-Point number 'b' is " << b.getRawBits() << '\n';
    std::cout << "The Integer Value of Fixed-Point number 'c' is " << c.getRawBits() << '\n';
    std::cout << "The Integer Value of Fixed-Point number 'd' is " << d.getRawBits() << '\n';
    std::cout << '\n';

    std::cout << "\033[1;34m" << "The Result of Converting Each Fixed-Point Number into Integer" << "\033[0m" << '\n';
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    std::cout << '\n';

    std::cout << "\033[1;34m" << "The negative floating number test" << "\033[0m" << '\n';
    Fixed neg(-1.5f);
    Fixed neg(-1.5f);
    Fixed neg2(-2);
    std::cout << "negative -1.5f print int => " << neg.toInt() << '\n';
    std::cout << "negative -1.5f print float => " << neg.toFloat() << '\n';
    std::cout << "negative -2 => " << neg2.toInt() << '\n';
    std::cout << "Literal -1.5f => " << (int)(-1.5f) << '\n';
    
    return 0;
}
