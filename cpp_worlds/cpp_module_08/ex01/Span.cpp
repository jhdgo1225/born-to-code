#include "Span.hpp"
#include <iostream>
#include <limits>

Span::Span(unsigned int n)
    :sz(n),
     curSize(0)
{
    storage.clear();
}

Span::~Span()
{
}

Span::Span(const Span& rhs)
    :sz(rhs.sz),
     curSize(rhs.curSize)
{
    std::multiset<int>::iterator it;
    for (it = rhs.storage.begin(); it != rhs.storage.end(); it++)
        storage.insert(*it);
}

Span& Span::operator=(const Span& rhs)
{
    sz = rhs.sz;
    curSize = rhs.curSize;
    storage.clear();
    std::multiset<int>::iterator it;
    for (it = rhs.storage.begin(); it != rhs.storage.end(); it++)
        storage.insert(*it);
    return (*this);
}

void    Span::addNumber(int n)
{
    if (sz == curSize)
    {
        std::cout << "The Span is Full." << '\n';
        return ;
    }
    storage.insert(n);
    curSize++;
}

unsigned int    Span::shortestSpan(void)
{
    if (curSize <= 1)
        return (0);
    std::multiset<int>::iterator it = storage.begin();
    unsigned int    now = *it;
    it++;
    unsigned int    span = std::numeric_limits<unsigned int>::max();
    while (it != storage.end())
    {
        if (span > *it - now)
            span = *it - now;
        now = *it;
        it++;
    }
    return (span);
}

unsigned int    Span::longestSpan(void)
{
    if (curSize <= 1)
        return (0);
    std::multiset<int>::iterator startIter = storage.begin();
    std::multiset<int>::iterator endIter = storage.end();
    endIter--;
    return (*endIter - *startIter);
}
