/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_a_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:08:20 by jonghopa          #+#    #+#             */
/*   Updated: 2023/09/27 19:21:31 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	high_a(t_deque *qa)
{
	deque_rotate(qa);
	write(1, "ra\n", 3);
}

void	mid_a(t_deque *qa, t_deque *qb)
{
	deque_push(qa, qb);
	write(1, "pb\n", 3);
}

void	low_a(t_deque *qb)
{
	if (deque_size(qb) > 1)
	{
		deque_rotate(qb);
		write(1, "rb\n", 3);
	}
}

void	concorrent_rotate_a(t_deque *qa, t_deque *qb)
{
	deque_rotate(qa);
	deque_rotate(qb);
	write(1, "rr\n", 3);
}
