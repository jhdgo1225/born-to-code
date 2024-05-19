#include "RPN.hpp"
#include <sstream>
#include <cstdlib>
#include <stack>

void RPN::calculate(const std::string& notation)
{
    std::istringstream ss(notation);
    std::string opr;
    std::stack<int> stk;
    while (std::getline(ss, opr, ' '))
    {
        if (opr.size() != 1)
        {
            std::cout << "Error" << '\n';
            return ;
        }
        if (!opr.compare("+") || !opr.compare("-") || !opr.compare("*") || !opr.compare("/"))
        {
            if (stk.size() <= 1)
            {
                std::cout << "Error" << '\n';
                return ;
            }
            int two = stk.top();
            stk.pop();
            int one = stk.top();
            stk.pop();
            if (!opr.compare("+"))
                stk.push(one + two);
            else if (!opr.compare("-"))
                stk.push(one - two);
            else if (!opr.compare("*"))
                stk.push(one * two);
            else
            {
                if (two == 0)
                {
                    std::cout << "Error" << '\n';
                    return ;
                }
                stk.push(one / two);
            }
        }
        else if (opr[0] >= '0' && opr[0] <= '9')
            stk.push(atoi(opr.c_str()));
        else
        {
            std::cout << "Error" << '\n';
            return ;
        }
    }
    if (stk.size() != 1)
    {
        std::cout << "Error" << '\n';
        return ;
    }
    std::cout << stk.top() << '\n';
}
