#include "easyfind.hpp"
#include <iostream>
#include <list>

int main(void)
{
	std::list<int> hello;

	try {
		std::cout << "'[list] Container' Test" << '\n';
		std::cout << "-----------------------------------" << '\n';
		hello.push_back(12);
		hello.push_back(24);
		hello.push_back(36);
		std::list<int>::iterator iter1 = ::easyfind(hello, 36);
		std::cout << *iter1 << '\n';
		std::cout << '\n';

		std::cout << "Looping Statement Test" << '\n';
		while (iter1 != hello.end())
			std::cout << *iter1++ << '\n';
	} catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}
	return (0);
}
