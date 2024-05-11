#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>

template<typename T>
bool easyfind(T& container, int target)
{
	typename T::iterator it = find(container.begin(), container.end(), target);
	if (it == container.end())
		return (false);
	else
		return (true);
}

#endif
