/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_push_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:46:07 by jonghopa          #+#    #+#             */
/*   Updated: 2023/09/09 13:46:08 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	deque_push_back(t_deque *deque, int content)
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
		tmp = deque->back;
		new->left = tmp;
		tmp->right = new;
		deque->back = new;
	}
	return (1);
}
