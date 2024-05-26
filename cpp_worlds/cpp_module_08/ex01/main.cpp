#include "Span.hpp"
#include <iostream>
#include <vector>

int main(void)
{
    Span sp = Span(5);
    Span sp2 = Span(10);
    Span sp3 = Span(10000);
    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(11);
        sp.addNumber(9);
        std::cout << sp.shortestSpan() << '\n';
        std::cout << sp.longestSpan() << '\n';
    } catch(Span::EmptyOrOnlyOneError& e) {
        std::cout << e.what() << '\n';
    } catch(Span::FullError& e) {
        std::cout << e.what() << '\n';
    }
    std::cout << "==========================================" << '\n';
    try {
        sp.addNumber(12);
        std::cout << sp.shortestSpan() << '\n';
        std::cout << sp.longestSpan() << '\n';
    } catch(Span::EmptyOrOnlyOneError& e) {
        std::cout << e.what() << '\n';
    } catch(Span::FullError& e) {
        std::cout << e.what() << '\n';
    }
    std::cout << "==========================================" << '\n';
    try {
        sp2 = sp;
        sp2.addNumber(2);
        std::cout << sp2.shortestSpan() << '\n';
        std::cout << sp2.longestSpan() << '\n';
    } catch(Span::EmptyOrOnlyOneError& e) {
        std::cout << e.what() << '\n';
    } catch(Span::FullError& e) {
        std::cout << e.what() << '\n';
    }
    std::cout << "==========================================" << '\n';
    try {
        std::vector<int> vt;
        for (int i=1; i<=10000; i++)
            vt.push_back(i);
        sp3.addNumber<std::vector<int> >(vt.begin(), vt.end());
        std::cout << sp3.shortestSpan() << '\n';
        std::cout << sp3.longestSpan() << '\n';
    } catch(Span::EmptyOrOnlyOneError& e) {
        std::cout << e.what() << '\n';
    } catch(Span::FullError& e) {
        std::cout << e.what() << '\n';
    }
    return (0);
}