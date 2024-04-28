#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template<typename T>
void    iter(T *arr, int size, void (*func)(T&))
{
    for (int i=0; i<size; i++)
        (*func)(arr[i]);
}

template<typename T>
void    plus(T& ref)
{
    ref += 123;
}

template<typename T>
void    printModule(T& ref)
{
    std::cout << ref << '\n';
}

#endif
