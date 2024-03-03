#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat& rhs);
    Cat& operator=(const Cat& rhs);
    virtual         ~Cat();
    virtual void    makeSound() const;
    void            addIdeas(const std::string idea);
    void            showIdeas();
private:
    Brain   *brain;
    int     idx;
};

#endif
