#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>

class RPN
{
public:
    static void calculate(const std::string& notation);
private:
    RPN();
    ~RPN();
    RPN(const RPN& rhs);
    RPN& operator=(const RPN& rhs);
};

#endif
