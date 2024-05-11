#ifndef SPAN_HPP
# define SPAN_HPP
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

#endif
