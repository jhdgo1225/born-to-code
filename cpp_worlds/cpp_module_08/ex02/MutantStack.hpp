#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP
# include <iostream>
# include <stack>
# include <deque>

// MutantStack 클래스 정의
template<typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	MutantStack()
	{
	}
	~MutantStack()
	{
	}
	MutantStack(const MutantStack<T, Container>& rhs)
		:std::stack<T, Container>(rhs)
	{
	}
	MutantStack<T, Container>& operator=(const MutantStack<T, Container>& rhs)
	{
		std::stack<T, Container>::operator=(rhs);
		return (*this);
	}
	typedef typename std::stack<T, Container>::container_type::iterator iterator;
    iterator begin()
	{
		return (this->c.begin());
	}
	iterator end()
	{
		return (this->c.end());
	}
};

#endif
