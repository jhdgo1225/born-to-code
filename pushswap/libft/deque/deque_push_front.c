/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_push_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:19:15 by jonghopa          #+#    #+#             */
/*   Updated: 2023/09/09 11:19:16 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	deque_push_front(t_deque *deque, int content)
{
	t_deque_node	*new;
	t_deque_node	*tmp;

	if (deque == NULL)
		return (0);
	new = deque_create_node(content);
	if (new == NULL)
		return (0);
	if (deque->front == NULL && deque->back == NULL)
	{
		deque->front = new;
		deque->back = new;
	}
	else
	{
		tmp = deque->front;
		new->right = tmp;
		tmp->left = new;
		deque->front = new;
	}
	return (1);
}
