/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sorting_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:06:11 by jonghopa          #+#    #+#             */
/*   Updated: 2023/09/27 16:17:48 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_sorting_four_a_2(t_deque *qa, t_deque *qb)
{
	deque_reverse_rotate(qa);
	deque_reverse_rotate(qa);
	write(1, "rra\n", 4);
	write(1, "rra\n", 4);
	if (qa->front->content > qa->front->right->content
		&& qb->front->content < qb->front->right->content)
	{
		deque_swap(qa);
		deque_swap(qb);
		write(1, "ss\n", 3);
	}
	else if (qa->front->content > qa->front->right->content)
	{
		deque_swap(qa);
		write(1, "sa\n", 3);
	}
	else if (qb->front->content < qb->front->right->content)
	{
		deque_swap(qb);
		write(1, "sb\n", 3);
	}
	deque_push(qb, qa);
	deque_push(qb, qa);
	write(1, "pa\n", 3);
	write(1, "pa\n", 3);
}

void	hard_sorting_four_a(t_deque *qa, t_deque *qb, int end)
{
	int				cnt;
	t_deque_node	*ptr;

	cnt = 4;
	while (cnt--)
	{
		ptr = qa->front;
		if (ptr->content == end - 1 || ptr->content == end - 2)
		{
			deque_rotate(qa);
			write(1, "ra\n", 3);
		}
		else
		{
			deque_push(qa, qb);
			write(1, "pb\n", 3);
		}
	}
	hard_sorting_four_a_2(qa, qb);
}

void	hard_sorting_a(t_deque *qa, t_deque *qb, int start, int end)
{
	int	cnt;

	cnt = end - start;
	if (cnt == 1)
		return ;
	else if (cnt == 2)
	{
		if (qa->front->content > qa->front->right->content)
		{
			deque_swap(qa);
			write(1, "sa\n", 3);
		}
	}
	else if (cnt == 3)
	{
		if (cnt == deque_size(qa))
			hard_sorting_three_a_special(qa);
		else
			hard_sorting_three_a(qa, qb, end);
	}
	else if (cnt == 4)
		hard_sorting_four_a(qa, qb, end);
}
