#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP
# include <cstdlib>
# include <stack>

template<typename T>
class MutantStack
{
public:
    MutantStack()
        :_size(0)
    {
    }
    ~MutantStack()
    {
    }
    MutantStack(const MutantStack<T>& rhs)
        :_size(rhs._size)
    {
        ogStack = rhs.ogStack;
    }
    MutantStack& operator=(const MutantStack<T>& rhs)
    {
        ogStack = rhs.ogStack;
        _size = rhs._size;
        return (*this);
    }
    void    push(T data)
    {
        ogStack.push(data);
    }
    void    pop()
    {
        ogStack.pop();
    }
    size_t    size()
    {
        return (ogStack.size());
    }
    bool    empty()
    {
        return (ogStack.empty());
    }
    T&      top()
    {
        return (ogStack.top());
    }
    void    swap(const MutantStack& rhs)
    {
        ogStack.swap(rhs.ogStack);
    }
private:
    size_t          _size;
    std::stack<T>   ogStack;
};

#endif
