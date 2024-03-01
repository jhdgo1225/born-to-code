#ifndef UNUSED_MATERIA_COLLECTOR_HPP
# define UNUSED_MATERIA_COLLECTOR_HPP
# include "AMateria.hpp"

typedef struct s_node
{
	AMateria		*value;
	struct s_node	*next;
}				t_node;

class UnusedMateriaCollector
{
public:
	UnusedMateriaCollector();
	~UnusedMateriaCollector();
	void	push(AMateria* unequip);
	void	deleteAll();
private:
	UnusedMateriaCollector(const UnusedMateriaCollector& rhs);
	UnusedMateriaCollector& operator=(const UnusedMateriaCollector& rhs);
	t_node *front;
	t_node *back;
};

#endif
