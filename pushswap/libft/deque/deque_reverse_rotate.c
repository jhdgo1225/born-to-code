/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:56:34 by jonghopa          #+#    #+#             */
/*   Updated: 2023/09/13 14:56:35 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deque_reverse_rotate(t_deque *deque)
{
	t_deque_node	*tmp;

	if (deque_size(deque) <= 1)
		return ;
	tmp = deque->back;
	deque->back = tmp->left;
	deque->back->right = NULL;
	tmp->left = NULL;
	tmp->right = deque->front;
	deque->front->left = tmp;
	deque->front = tmp;
}
