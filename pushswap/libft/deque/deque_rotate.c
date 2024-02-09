/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:56:38 by jonghopa          #+#    #+#             */
/*   Updated: 2023/09/13 14:56:39 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deque_rotate(t_deque *deque)
{
	t_deque_node	*tmp;

	if (deque_size(deque) <= 1)
		return ;
	tmp = deque->front;
	deque->front = tmp->right;
	deque->front->left = NULL;
	tmp->right = NULL;
	tmp->left = deque->back;
	deque->back->right = tmp;
	deque->back = tmp;
}
