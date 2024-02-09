/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sorting_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:06:14 by jonghopa          #+#    #+#             */
/*   Updated: 2023/09/27 17:30:21 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_sorting_four_b_2(t_deque *qb, t_deque *qa)
{
	deque_reverse_rotate(qb);
	deque_reverse_rotate(qb);
	write(1, "rrb\n", 4);
	write(1, "rrb\n", 4);
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

void	hard_sorting_four_b(t_deque *qb, t_deque *qa, int end)
{
	int				cnt;
	t_deque_node	*ptr;

	cnt = 4;
	while (cnt--)
	{
		ptr = qb->front;
		if (ptr->content == end - 1 || ptr->content == end - 2)
		{
			deque_push(qb, qa);
			write(1, "pa\n", 3);
		}
		else
		{
			deque_rotate(qb);
			write(1, "rb\n", 3);
		}
	}
	hard_sorting_four_b_2(qb, qa);
}

void	hard_sorting_b(t_deque *qb, t_deque *qa, int start, int end)
{
	int	cnt;

	cnt = end - start;
	if (cnt == 1)
	{
		deque_push(qb, qa);
		write(1, "pa\n", 3);
	}
	else if (cnt == 2)
	{
		if (qb->front->content < qb->front->right->content)
		{
			deque_swap(qb);
			write(1, "sb\n", 3);
		}
		deque_push(qb, qa);
		deque_push(qb, qa);
		write(1, "pa\n", 3);
		write(1, "pa\n", 3);
	}
	else if (cnt == 3)
		hard_sorting_three_b(qb, qa, end);
	else if (cnt == 4)
		hard_sorting_four_b(qb, qa, end);
}
