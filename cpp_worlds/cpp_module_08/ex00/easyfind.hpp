#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <stdexcept>

template<typename T>
typename T::iterator easyfind(T& container, int target)
{

	typename T::iterator it = find(container.begin(), container.end(), target);
	if (it == container.end())
		throw std::out_of_range("Non-existent element");
	return (it);
}

#endif
