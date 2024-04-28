#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void    swap(T& n1, T& n2)
{
    T temp = n1;
    n1 = n2;
    n2 = temp;
}

template<typename T>
T min(const T& n1, const T& n2)
{
    return (n1 < n2) ? n1 : n2;
}

template<typename T>
T max(const T& n1, const T& n2)
{
    return (n1 > n2) ? n1 : n2;
}

#endif
