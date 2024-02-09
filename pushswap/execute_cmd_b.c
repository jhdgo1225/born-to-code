/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:06:06 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/05 21:42:33 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_available_b(t_deque *qa, t_deque *qb, int start, int mid1)
{
	if (qb->front->content >= start && qb->front->content < mid1)
		concorrent_rotate_b(qb, qa);
	else
		mid_b(qa);
}

void	execute_cmd_b_eq_size(t_deque *qb, t_deque *qa, int start, int end)
{
	int				mid1;
	int				mid2;
	int				cnt;

	cnt = end - start;
	mid1 = start + (end - start) / 3;
	mid2 = start + (end - start) * 2 / 3;
	while (cnt > mid1 - start)
	{
		if (qb->front->content >= start && qb->front->content < mid1)
			low_b(qb);
		else if (qb->front->content >= mid1 && qb->front->content < mid2)
		{
			high_b(qb, qa);
			is_available_b(qa, qb, start, mid1);
			cnt--;
		}
		else if (qb->front->content >= mid2 && qb->front->content < end)
		{
			high_b(qb, qa);
			cnt--;
		}
	}
}

void	execute_cmd_b(t_deque *qb, t_deque *qa, int start, int end)
{
	int				mid1;
	int				mid2;
	int				cnt;

	cnt = end - start;
	mid1 = start + (end - start) / 3;
	mid2 = start + (end - start) * 2 / 3;
	while (cnt-- > 0)
	{
		if (qb->front->content >= start && qb->front->content < mid1)
			low_b(qb);
		else if (qb->front->content >= mid1 && qb->front->content < mid2)
		{
			high_b(qb, qa);
			if (qb->front->content >= start && qb->front->content < mid1)
			{
				concorrent_rotate_b(qb, qa);
				cnt--;
			}
			else
				mid_b(qa);
		}
		else if (qb->front->content >= mid2 && qb->front->content < end)
			high_b(qb, qa);
	}
}
