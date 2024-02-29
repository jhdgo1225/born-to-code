#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
public:
    Brain();
    Brain(const Brain& rhs);
    Brain& operator=(const Brain& rhs);
    ~Brain();
    void        setIdea(const std::string idea, int i);
    std::string getIdea(int i);
private:
    std::string ideas[100];
};

#endif
