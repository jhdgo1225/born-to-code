/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:30:00 by jonghopa          #+#    #+#             */
/*   Updated: 2023/09/09 11:30:01 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_deque_node	*deque_create_node(int content)
{
	t_deque_node	*new;

	new = (t_deque_node *)malloc(sizeof(t_deque_node));
	if (new == NULL)
		return (NULL);
	new->left = NULL;
	new->right = NULL;
	new->content = content;
	return (new);
}
