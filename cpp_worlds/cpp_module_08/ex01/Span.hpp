#ifndef SPAN_HPP
# define SPAN_HPP
# include <algorithm>
# include <set>

class Span
{
public:
    class   FullError: public std::exception {
    public:
        const char *what();
    };
    class   EmptyOrOnlyOneError: public std::exception {
    public:
        const char *what();
    };
	Span(unsigned int n);
	~Span();
	Span(const Span& rhs);
	Span& operator=(const Span& rhs);
	void            addNumber(int n);
    template<typename Container>
    void    addNumber(typename Container::iterator s, typename Container::iterator e)
    {
        unsigned int	tmp = curSize + (e - s);
		if (tmp > sz)
			throw FullError();
		storage.insert(s, e);
		curSize = tmp;
    }
    unsigned int    shortestSpan(void);
    unsigned int    longestSpan(void);
private:
    unsigned int        sz;
    unsigned int        curSize;
    std::multiset<int>  storage;
};

#endif
