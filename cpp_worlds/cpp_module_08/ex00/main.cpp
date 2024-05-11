#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <queue>

int main(void)
{
	std::list<int> hello;

	hello.push_back(12);
	hello.push_back(24);
	hello.push_back(36);
	std::cout << (::easyfind(hello, 12) ? "Find!" : "Not Found") << '\n';

	// std::queue<int> st;
	// st.push(10);
	// st.push(20);
	// st.push(30);
	// st.push(40);
	// st.push(50);
	// std::cout << ::easyfind(st, 30) << '\n';
	return (0);
}
