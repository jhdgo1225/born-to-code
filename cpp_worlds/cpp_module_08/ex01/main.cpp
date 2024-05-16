#include "Span.hpp"
#include <iostream>
#include <vector>

int main(void)
{
    Span sp = Span(5);
    Span sp2 = Span(10);
    Span sp3 = Span(10000);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp2 = sp;
    std::cout << sp.shortestSpan() << '\n';
    sp2.addNumber(2);
    std::cout << sp2.longestSpan() << '\n';
    std::cout << "==========================================" << '\n';
    std::vector<int> vt;
    for (int i=1; i<=10000; i++)
        vt.push_back(i);
    ::addNumber<std::vector<int> >(vt.begin(), vt.end(), sp3);
    std::cout << sp3.shortestSpan() << '\n';
    std::cout << sp3.longestSpan() << '\n';
    return (0);
}