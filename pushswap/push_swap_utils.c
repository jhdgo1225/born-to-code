/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devpark <devpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:32:25 by jonghopa          #+#    #+#             */
/*   Updated: 2023/09/30 02:03:36 by devpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_descend_sort(t_deque *qb, int start, int end)
{
	int				i;
	t_deque_node	*ptr;

	ptr = qb->front;
	i = end - 1;
	while (i >= start)
	{
		if (i != ptr->content)
			return (0);
		ptr = ptr->right;
		i--;
	}
	return (1);
}

int	check_ascend_sort(t_deque *qa, int start, int end)
{
	int				i;
	t_deque_node	*ptr;

	ptr = qa->front;
	i = start;
	while (i < end)
	{
		if (i != ptr->content)
			return (0);
		ptr = ptr->right;
		i++;
	}
	return (1);
}
