/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sorting_three_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:17:00 by jonghopa          #+#    #+#             */
/*   Updated: 2023/09/27 18:48:27 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_sorting_three_a_2(t_deque *qa, t_deque *qb)
{
	if (deque_size(qa) != 2)
	{
		deque_reverse_rotate(qa);
		deque_reverse_rotate(qa);
		write(1, "rra\n", 4);
		write(1, "rra\n", 4);
	}
	if (qa->front->content > qa->front->right->content)
	{
		deque_swap(qa);
		write(1, "sa\n", 3);
	}
	deque_push(qb, qa);
	write(1, "pa\n", 3);
}

void	hard_sorting_three_a(t_deque *qa, t_deque *qb, int end)
{
	int				cnt;
	int				flag;
	t_deque_node	*ptr;

	cnt = 3;
	flag = 0;
	while (cnt--)
	{
		if (flag && deque_size(qa) <= 3)
			continue ;
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
			flag = 1;
		}
	}
	hard_sorting_three_a_2(qa, qb);
}

void	hard_sorting_three_a_special_2(t_deque *qa)
{
	int	three[3];

	three[0] = qa->front->content;
	three[1] = qa->front->right->content;
	three[2] = qa->front->right->right->content;
	if (three[0] < three[2])
	{
		deque_reverse_rotate(qa);
		deque_swap(qa);
		write(1, "rra\n", 4);
		write(1, "sa\n", 3);
	}
	else
	{
		deque_reverse_rotate(qa);
		write(1, "rra\n", 4);
	}
}

void	hard_sorting_three_a_special(t_deque *qa)
{
	int	three[3];

	three[0] = qa->front->content;
	three[1] = qa->front->right->content;
	three[2] = qa->front->right->right->content;
	if (three[0] > three[1])
	{
		if (three[0] > three[2])
		{
			deque_rotate(qa);
			write(1, "ra\n", 3);
			if (three[1] > three[2])
			{
				deque_swap(qa);
				write(1, "sa\n", 3);
			}
		}
		else
		{
			deque_swap(qa);
			write(1, "sa\n", 3);
		}
	}
	else
		hard_sorting_three_a_special_2(qa);
}
