#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP
# include <iostream>
# include <cstdlib>
# include <vector>
# include <list>

class PmergeMe
{
public:
    PmergeMe(int argc, char **argv);
    ~PmergeMe();
    PmergeMe(const PmergeMe& rhs);
    PmergeMe& operator=(const PmergeMe& rhs);
    void mergeInsertionSort();
private:
    PmergeMe();
    std::vector<std::pair<int, int> > vc;
    std::list<std::pair<int, int> > li;
};

#endif
