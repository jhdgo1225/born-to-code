/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_pop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:42:06 by jonghopa          #+#    #+#             */
/*   Updated: 2023/09/09 12:42:07 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deque_pop_front(t_deque *deque)
{
	t_deque_node	*tmp;

	if (deque_empty(deque))
		return ;
	tmp = deque->front;
	deque->front = tmp->right;
	if (deque->front == NULL)
		deque->back = NULL;
	else
		deque->front->left = NULL;
	tmp->right = NULL;
	free(tmp);
}
