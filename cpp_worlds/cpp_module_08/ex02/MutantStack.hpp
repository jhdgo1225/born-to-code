#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP
# include <iostream>
# include <stack>
# include <deque>

// MutantStack 클래스 정의
template<typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	class iterator
	{
	public:
		iterator()
			:_idx(-1)
		{
		}
		iterator(typename Container::iterator iter, int idx)
			:_iter(iter),
			 _idx(idx)
		{
		}
		~iterator()
		{
		}
        T& operator*()
		{
			return *_iter;
		}
		typename Container::iterator operator++(void)
		{
			return (_iter++);
		}
		typename Container::iterator operator--(void)
		{
			return (_iter--);
		}
		typename Container::iterator operator++(int _val)
		{
			(void)_val;
			typename Container::iterator tmp = _iter;
			_iter++;
			return (tmp);
		}
		typename Container::iterator operator--(int _val)
		{
			(void)_val;
			typename Container::iterator tmp = _iter;
			_iter--;
			return (tmp);
		}
        bool operator==(const iterator& a) const
        {
            return (_iter != a._iter);
        }
        bool operator!=(const iterator& a) const
        {
            return (_iter != a._iter);
        }
	private:
		typename Container::iterator	_iter;
		int								_idx;
	};
	MutantStack()
	{
	}
	~MutantStack()
	{
	}
    iterator begin()
	{
		Container* startAddr = &(this->c);
		return iterator(startAddr->begin(), 0);
	}
	iterator end()
	{
		Container* endAddr = &(this->c);
		return iterator(endAddr->end(), endAddr->size());
	}
};

#endif
