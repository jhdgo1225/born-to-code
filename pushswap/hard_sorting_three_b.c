/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sorting_three_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:30:27 by jonghopa          #+#    #+#             */
/*   Updated: 2023/09/27 18:48:32 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_sorting_three_b_3(t_deque *qb, t_deque *qa)
{
	if (deque_size(qb) != 1)
	{
		deque_reverse_rotate(qb);
		write(1, "rrb\n", 4);
	}
	if (qa->front->content > qa->front->right->content)
	{
		deque_swap(qa);
		write(1, "sa\n", 3);
	}
}

void	hard_sorting_three_b_2(t_deque *qb, t_deque *qa, int end)
{
	int				cnt;
	t_deque_node	*ptr;

	cnt = 3;
	while (cnt--)
	{
		if (deque_size(qb) == 1)
			continue ;
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
	hard_sorting_three_b_3(qb, qa);
}

void	hard_sorting_three_b(t_deque *qb, t_deque *qa, int end)
{
	int	three[3];

	three[0] = qb->front->content;
	three[1] = qb->front->right->content;
	three[2] = qb->front->right->right->content;
	if (three[0] > three[2] && three[1] > three[2])
	{
		if (three[0] < three[1])
		{
			deque_swap(qb);
			write(1, "sb\n", 3);
		}
		deque_push(qb, qa);
		deque_push(qb, qa);
		write(1, "pa\n", 3);
		write(1, "pa\n", 3);
	}
	else
		hard_sorting_three_b_2(qb, qa, end);
	deque_push(qb, qa);
	write(1, "pa\n", 3);
}
