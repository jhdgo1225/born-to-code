#include <iostream>
#include "Serializer.hpp"
#include <cstdlib>

int main(void)
{
    Data *test1 = new Data();
    test1->a = 10;
    test1->b = 590;
    test1->ch = 'A';
    test1->st = false;

    std::uintptr_t dataAddr = Serializer::serialize(test1);
    std::cout << std::hex << "0x" << dataAddr << '\n';
    std::cout << test1 << '\n';
    std::cout << std::dec;

    Data *test2 = Serializer::deserialize(dataAddr);
    std::cout << test1->a << '\n';
    std::cout << test2->a << '\n';
    std::cout << test1->b << '\n';
    std::cout << test2->b << '\n';
    std::cout << test1->ch << '\n';
    std::cout << test2->ch << '\n';
    std::cout << test1->st << '\n';
    std::cout << test2->st << '\n';

    delete test1;
    return (0);
}
