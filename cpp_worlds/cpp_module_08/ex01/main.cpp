#include "Span.hpp"
#include <iostream>

int main(void)
{
    Span sp = Span(5);
    Span sp2 = Span(10);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp2 = sp;
    std::cout << sp.shortestSpan() << '\n';
    sp2.addNumber(2);
    std::cout << sp2.longestSpan() << '\n';
    return (0);
}