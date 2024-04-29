#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base::~Base()
{
}

Base    *generate(void)
{
    Base    *ret;
    try {
        srand(time(NULL));
        int randNum = rand() % 99;
        if (randNum >= 0 && randNum < 33)
            ret = new A();
        else if (randNum >= 33 && randNum < 66)
            ret = new B();
        else if (randNum >= 66 && randNum < 99)
            ret = new C();
    } catch (std::bad_alloc& exception) {
        std::cout << "exception : " << exception.what() << '\n';
        std::abort();
    }
    return (ret);
}

void    identify(Base *p)
{
    A   *testA = dynamic_cast<A*>(p);
    B   *testB = dynamic_cast<B*>(p);;
    C   *testC = dynamic_cast<C*>(p);;
    if (testA != NULL)
        std::cout << "A" << '\n';
    else if (testB != NULL)
        std::cout << "B" << '\n';
    else if (testC != NULL)
        std::cout << "C" << '\n';
    else
        std::cout << "Not A, B, or C" << '\n';
}

void    identify(Base &p)
{
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << '\n';
    } catch (std::exception &e1) {
        try {
            dynamic_cast<B&>(p);
            std::cout << "B" << '\n';
        } catch (std::exception &e2) {
            try {
                dynamic_cast<C&>(p);
                std::cout << "C" << '\n';
            } catch (std::exception &e3) {
                std::cout << e3.what() << '\n';
            }
        }
    }
}
