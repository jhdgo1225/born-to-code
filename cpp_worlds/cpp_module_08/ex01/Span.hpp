#ifndef SPAN_HPP
# define SPAN_HPP
# include <algorithm>
# include <set>

class Span
{
public:
	Span(unsigned int n);
	~Span();
	Span(const Span& rhs);
	Span& operator=(const Span& rhs);
	void            addNumber(int n);
    unsigned int    shortestSpan(void);
    unsigned int    longestSpan(void);
private:
    unsigned int        sz;
    unsigned int        curSize;
    std::multiset<int>  storage;
};

template<typename Container>
void    addNumber(typename Container::iterator s, typename Container::iterator e, Span& span)
{
    while (s != e)
        span.addNumber(*s++);
}

#endif
