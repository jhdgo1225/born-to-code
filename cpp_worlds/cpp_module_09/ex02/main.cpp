#include "PmergeMe.hpp"

void    checkArguments(int argc, char **argv)
{
    if (argc <= 1)
    {
        std::cerr << "Error" << '\n';
        exit(1);
    }
    long long   overflowChecker;
    size_t      lengthChecker;
    for (int idx = 1; idx < argc; idx++)
    {
        overflowChecker = 0;
        lengthChecker = 0;
        for (int idx2 = 0; argv[idx][idx2]; idx2++)
        {
            if (!(argv[idx][idx2] >= '0' && argv[idx][idx2] <= '9'))
            {
                std::cerr << "Error" << '\n';
                exit(2);
            }
            overflowChecker = overflowChecker * 10 + (argv[idx][idx2] - '0');
            if (overflowChecker > 2147483647)
            {
                std::cerr << "Error" << '\n';
                exit(3);
            }
            lengthChecker++;
        }
        if (!lengthChecker)
        {
            std::cerr << "Error" << '\n';
            exit(4);
        }
    }
}

int main(int argc, char **argv)
{
    checkArguments(argc, argv);
    PmergeMe one(argc, argv);
    one.mergeInsertionSort();
    return (0);
}
