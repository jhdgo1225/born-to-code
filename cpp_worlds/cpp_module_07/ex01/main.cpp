#include "iter.hpp"
#include <iostream>

void    print(int& num)
{
    std::cout << num << '\n';
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };

  iter( tab, 5, print<const int> );
  iter( tab, 5, print );
  iter(tab, 5, plus);
  iter(tab, 5, print);

  return 0;
}
