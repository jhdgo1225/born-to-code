#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

PmergeMe::PmergeMe(int argc, char **argv)
{
    for (int idx = 1; idx < argc; idx++)
    {
        int tmp = atoi(argv[idx]);
        vc.push_back(tmp);
        li.push_back(tmp);
    }
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& rhs)
{
    vc = rhs.vs;
    li = rhs.li;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    vc.clear();
    li.clear();
    vc = rhs.vs;
    li = rhs.li;
    return (*this);
}

void PmergeMe::MergeInsertionSortWithVector()
{
    
}

void PmergeMe::MergeInsertionSortWithList()
{

}