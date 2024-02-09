/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:56:27 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/03 18:45:13 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deque_push(t_deque *src, t_deque *dst)
{
	t_deque_node	*tmp;

	if (src->front == NULL)
		return ;
	tmp = src->front;
	src->front = tmp->right;
	if (src->front == NULL)
		src->back = NULL;
	else
		src->front->left = NULL;
	tmp->right = NULL;
	if (dst->front == NULL)
		dst->back = tmp;
	else
	{
		dst->front->left = tmp;
		tmp->right = dst->front;
	}
	dst->front = tmp;
}

void	deque_swap(t_deque *deque)
{
	t_deque_node	*tmp;
	size_t			size;

	size = deque_size(deque);
	if (size <= 1)
		return ;
	tmp = deque->front;
	deque->front = tmp->right;
	if (size == 2)
	{
		deque->back = tmp;
		deque->front->right = tmp;
		tmp->left = deque->front;
		tmp->right = NULL;
		deque->front->left = NULL;
	}
	else
	{
		deque->front->right->left = tmp;
		tmp->right = deque->front->right;
		deque->front->left = NULL;
		deque->front->right = tmp;
		tmp->left = deque->front;
	}
}
