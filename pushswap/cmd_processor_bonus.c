/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_processor_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:53:14 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/05 21:06:15 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdio.h>

int	check_ascend_sort(t_deque *qa, int start, int end)
{
	int				i;
	t_deque_node	*ptr;

	ptr = qa->front;
	if (ptr == NULL)
		return (0);
	i = start;
	while (i < end)
	{
		if (i != ptr->content)
			return (0);
		ptr = ptr->right;
		i++;
	}
	return (1);
}

int	check_cmd_plus(t_deque *qa, t_deque *qb, char *cmd)
{
	size_t	len;

	len = ft_strlen(cmd);
	if (ft_strncmp(cmd, "ra\n", len + 1) == 0)
		deque_rotate(qa);
	else if (ft_strncmp(cmd, "rb\n", len + 1) == 0)
		deque_rotate(qb);
	else if (ft_strncmp(cmd, "rr\n", len + 1) == 0)
	{
		deque_rotate(qa);
		deque_rotate(qb);
	}
	else if (ft_strncmp(cmd, "rra\n", len + 1) == 0)
		deque_reverse_rotate(qa);
	else if (ft_strncmp(cmd, "rrb\n", len + 1) == 0)
		deque_reverse_rotate(qb);
	else if (ft_strncmp(cmd, "rrr\n", len + 1) == 0)
	{
		deque_reverse_rotate(qa);
		deque_reverse_rotate(qb);
	}
	else
		return (0);
	return (1);
}

int	check_cmd(t_deque *qa, t_deque *qb, char *cmd)
{
	size_t	len;
	int		check;

	check = 1;
	len = ft_strlen(cmd);
	if (ft_strncmp(cmd, "sa\n", len + 1) == 0)
		deque_swap(qa);
	else if (ft_strncmp(cmd, "sb\n", len + 1) == 0)
		deque_swap(qb);
	else if (ft_strncmp(cmd, "ss\n", len + 1) == 0)
	{
		deque_swap(qa);
		deque_swap(qb);
	}
	else if (ft_strncmp(cmd, "pa\n", len + 1) == 0)
		deque_push(qb, qa);
	else if (ft_strncmp(cmd, "pb\n", len + 1) == 0)
		deque_push(qa, qb);
	else
		check = check_cmd_plus(qa, qb, cmd);
	if (check == 0)
		return (0);
	return (1);
}

int	cmd_processors(t_deque *qa, t_deque *qb)
{
	char	*cmd;
	int		size;
	int		check;

	size = deque_size(qa);
	while (1)
	{
		cmd = get_next_line(0);
		if (cmd == NULL)
			break ;
		check = check_cmd(qa, qb, cmd);
		free(cmd);
		if (check == 0)
			return (0);
	}
	if (deque_size(qa) == size && deque_empty(qb)
		&& check_ascend_sort(qa, 0, size))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (1);
}
