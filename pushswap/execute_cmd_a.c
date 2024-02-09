/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:06:01 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/05 21:44:29 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_available_a(t_deque *qa, t_deque *qb, int mid2, int end)
{
	if (qa->front->content >= mid2 && qa->front->content < end)
		concorrent_rotate_a(qa, qb);
	else
		low_a(qb);
}

void	execute_cmd_a_eq_size(t_deque *qa, t_deque *qb, int start, int end)
{
	int				mid1;
	int				mid2;
	int				cnt;

	cnt = end - start;
	mid1 = start + (end - start) / 3;
	mid2 = start + (end - start) * 2 / 3;
	while (cnt > end - mid2)
	{
		if (qa->front->content >= start && qa->front->content < mid1)
		{
			mid_a(qa, qb);
			is_available_a(qa, qb, mid2, end);
			cnt--;
		}
		else if (qa->front->content >= mid1 && qa->front->content < mid2)
		{
			mid_a(qa, qb);
			cnt--;
		}
		else if (qa->front->content >= mid2 && qa->front->content < end)
			high_a(qa);
	}
}

void	execute_cmd_a(t_deque *qa, t_deque *qb, int start, int end)
{
	int				mid1;
	int				mid2;
	int				cnt;

	cnt = end - start;
	mid1 = start + (end - start) / 3;
	mid2 = start + (end - start) * 2 / 3;
	while (cnt-- > 0)
	{
		if (qa->front->content >= start && qa->front->content < mid1)
		{
			mid_a(qa, qb);
			if (qa->front->content >= mid2 && qa->front->content < end)
			{
				concorrent_rotate_a(qa, qb);
				cnt--;
			}
			else
				low_a(qb);
		}
		else if (qa->front->content >= mid1 && qa->front->content < mid2)
			mid_a(qa, qb);
		else if (qa->front->content >= mid2 && qa->front->content < end)
			high_a(qa);
	}
}
