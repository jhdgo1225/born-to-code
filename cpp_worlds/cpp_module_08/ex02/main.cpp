#include "MutantStack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(-123);
    mstack.push(737);
    std::cout << mstack.top() << std::endl;
    std::cout << mstack.size() << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << *(it++) << '\n';
    std::cout << *(it--) << '\n';
    std::cout << "=================================\n";
    std::cout << "Copy Constructor And Copy Assignment Operator\n";
    MutantStack<int> mstackCopy(mstack);
    std::cout << mstackCopy.top() << '\n';
    std::cout << mstackCopy.size() << '\n';
    mstackCopy.push(90);
    mstackCopy.push(100);
    std::cout << mstackCopy.top() << '\n';
    std::cout << mstackCopy.size() << '\n';
    MutantStack<int>::iterator it2 = mstackCopy.begin();
    while (it2 != mstackCopy.end())
    {
        std::cout << *it2++ << '\n';
    }
    std::cout << "=================================\n";
    std::cout << "Check Iterating with While Statement\n";
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << s.top() << '\n';
    return 0;
}
