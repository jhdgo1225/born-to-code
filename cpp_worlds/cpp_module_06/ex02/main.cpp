#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main(void)
{
    Base *test = generate();
    identify(test);

    Base &test2 = *test;
    identify(test2);

    delete test;
    return (0);
}
