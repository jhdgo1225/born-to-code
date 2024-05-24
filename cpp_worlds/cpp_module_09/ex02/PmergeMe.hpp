#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP
# include <vector>
# include <list>

class PmergeMe
{
public:
    PmergeMe(int argc, char **argv);
    ~PmergeMe();
    PmergeMe(const PmergeMe& rhs);
    PmergeMe& operator=(const PmergeMe& rhs);
    MergeInsertionSortWithVector(int argc, char **argv);
    MergeInsertionSortWithList(int argc, char **argv);
private:
    PmergeMe();
    std::vector<int>    vc;
    std::list<int>      li;
}

#endif
