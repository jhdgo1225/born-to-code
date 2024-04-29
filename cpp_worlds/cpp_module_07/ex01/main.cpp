#include "iter.hpp"

void    print(int& num)
{
    std::cout << num << '\n';
}

int main(void)
{
    int arr[3] = {1, 2, 3};
    ::iter(arr, 3, print);
    std::string arr2[3] = {"abc", "def", "ghi"};
    ::iter(arr2, 3, printModule);
    return (0);
}