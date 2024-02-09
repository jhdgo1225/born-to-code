/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:06:31 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/05 21:44:37 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rise_elements_a(t_deque *deque, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		deque_reverse_rotate(deque);
		write(1, "rra\n", 4);
		i++;
	}
}

void	push_swap_up_a(t_deque *qa, t_deque *qb, int start, int end)
{
	int	mid1;
	int	mid2;

	if (check_ascend_sort(qa, start, end))
		return ;
	if (end - start <= 4)
	{
		hard_sorting_a(qa, qb, start, end);
		return ;
	}
	mid1 = start + (end - start) / 3;
	mid2 = start + (end - start) * 2 / 3;
	if (deque_size(qa) == end - start)
		execute_cmd_a_eq_size(qa, qb, start, end);
	else
		execute_cmd_a(qa, qb, start, end);
	push_swap_down_a(qa, qb, mid2, end);
	push_swap_up_b(qb, qa, mid1, mid2);
	push_swap_down_b(qb, qa, start, mid1);
}

void	push_swap_down_a(t_deque *qa, t_deque *qb, int start, int end)
{
	int	size;

	size = end - start;
	if (deque_size(qa) != size)
		rise_elements_a(qa, size);
	push_swap_up_a(qa, qb, start, end);
}
