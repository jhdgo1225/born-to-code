#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    
    // Fixed c(a);
    // if (a * b = c)
    //     std::cout << "good!\n";
    // else
    //     std::cout << "bad\n";
    
    // Fixed a(10.01f);
    // Fixed b(10.0f);
    // Fixed c(a);

    // std::cout << "========= Fixed-Point Number =========\n";
    // std::cout << a << '\n';
    // std::cout << b << '\n';
    // std::cout << '\n';

    // std::cout << "========= Arithmetic Operator Results =========\n";
    // std::cout << (a + b) << '\n';
    // std::cout << (a - b) << '\n';
    // std::cout << (a * b) << '\n';
    // std::cout << (a / b) << '\n';
    // std::cout << '\n';

    // std::cout << "========= Logical Operator Results =========\n";
    // std::cout << (a > b) << '\n';
    // std::cout << (a >= b) << '\n';
    // std::cout << (a < b) << '\n';
    // std::cout << (a <= b) << '\n';
    // std::cout << (a != b) << '\n';
    // std::cout << (a == b) << '\n';
    // std::cout << '\n';

    // std::cout << "========= Unary Operator Results =========\n";
    // std::cout << "a++: " << a++ << '\n';
    // std::cout << "++a: " << ++a << '\n';
    // std::cout << "a--: " << a-- << '\n';
    // std::cout << "--a: " << --a << '\n';
    // std::cout << "b++: " << b++ << '\n';
    // std::cout << "++b: " << ++b << '\n';
    // std::cout << "b--: " << b-- << '\n';
    // std::cout << "--b: " << --b << '\n';
    // std::cout << '\n';

    // std::cout << "========= min() / max() Function Results =========\n";
    // const Fixed ca(50.471f);
    // const Fixed cb(50.47f);
    // std::cout << "max() Function: " << std::max(a, b) << '\n';
    // std::cout << "min() Function: " << std::min(a, b) << '\n';
    // std::cout << "max() Function: " << std::max(ca, cb) << '\n';
    // std::cout << "min() Function: " << std::min(ca, cb) << '\n';

    return 0;
}
