/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_b_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:01:47 by jonghopa          #+#    #+#             */
/*   Updated: 2023/09/27 19:26:17 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	high_b(t_deque *qb, t_deque *qa)
{
	deque_push(qb, qa);
	write(1, "pa\n", 3);
}

void	mid_b(t_deque *qa)
{
	deque_rotate(qa);
	write(1, "ra\n", 3);
}

void	low_b(t_deque *qb)
{
	deque_rotate(qb);
	write(1, "rb\n", 3);
}

void	concorrent_rotate_b(t_deque *qb, t_deque *qa)
{
	deque_rotate(qa);
	deque_rotate(qb);
	write(1, "rr\n", 3);
}
