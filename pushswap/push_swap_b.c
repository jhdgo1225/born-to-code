/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:06:35 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/05 21:42:59 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_to_a(t_deque *qb, t_deque *qa, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		deque_push(qb, qa);
		write(1, "pa\n", 3);
		i++;
	}
}

void	rise_elements_b(t_deque *deque, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		deque_reverse_rotate(deque);
		write(1, "rrb\n", 4);
		i++;
	}
}

void	push_swap_up_b(t_deque *qb, t_deque *qa, int start, int end)
{
	int	mid1;
	int	mid2;

	mid1 = start + (end - start) / 3;
	mid2 = start + (end - start) * 2 / 3;
	if (check_descend_sort(qb, start, end))
	{
		push_all_to_a(qb, qa, end - start);
		return ;
	}
	if ((end - start) <= 4)
	{
		hard_sorting_b(qb, qa, start, end);
		return ;
	}
	if (deque_size(qb) == (end - start))
		execute_cmd_b_eq_size(qb, qa, start, end);
	else
		execute_cmd_b(qb, qa, start, end);
	push_swap_up_a(qa, qb, mid2, end);
	push_swap_down_a(qa, qb, mid1, mid2);
	push_swap_down_b(qb, qa, start, mid1);
}

void	push_swap_down_b(t_deque *qb, t_deque *qa, int start, int end)
{
	int	size;

	size = end - start;
	if (deque_size(qb) != size)
		rise_elements_b(qb, size);
	push_swap_up_b(qb, qa, start, end);
}
