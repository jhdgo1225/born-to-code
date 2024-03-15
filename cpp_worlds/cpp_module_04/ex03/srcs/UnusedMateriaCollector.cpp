#include "UnusedMateriaCollector.hpp"
#include <cstdlib>

UnusedMateriaCollector::UnusedMateriaCollector()
	:front(NULL),
	 back(NULL)
{
}

UnusedMateriaCollector::~UnusedMateriaCollector()
{
}

UnusedMateriaCollector& UnusedMateriaCollector::operator=(const UnusedMateriaCollector& rhs)
{
	deleteAll();
	t_node	*tmp = rhs.front;
	while (tmp)
	{
		push(tmp->value->clone());
		tmp = tmp->next;
	}
	return *this;
}

void	UnusedMateriaCollector::push(AMateria* unequip)
{
	try
	{
		t_node	*tmp = new t_node;
		tmp->value = unequip;
		tmp->next = NULL;
		if (!front)
		{
			front = tmp;
			back = tmp;
			return ;
		}
		back->next = tmp;
		back = tmp;
	}
	catch (std::bad_alloc& exception)
	{
		std::cout << "exception : " << exception.what() << '\n';
        std::abort();
	}
}

void	UnusedMateriaCollector::deleteAll()
{
	t_node	*old;
	back = NULL;
	while (front)
	{
		old = front;
		front = front->next;
		old->next = NULL;
		delete old->value;
		delete old;
	}
}
