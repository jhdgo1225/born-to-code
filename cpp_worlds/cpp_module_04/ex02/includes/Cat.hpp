#ifndef CAT_HPP
# define CAT_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
public:
    Cat();
    Cat(const Cat& rhs);
    Cat& operator=(const Cat& rhs);
    virtual         ~Cat();
    virtual void    makeSound();
    void            addIdeas(const std::string idea);
    void            showIdeas();
private:
    Brain   *brain;
    int     idx;
};

#endif
