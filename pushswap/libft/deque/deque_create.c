/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:34:30 by jonghopa          #+#    #+#             */
/*   Updated: 2023/09/08 16:40:15 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_deque	*deque_create(void)
{
	t_deque	*deque;

	deque = (t_deque *)malloc(sizeof(t_deque));
	if (deque == NULL)
		return (NULL);
	deque->front = NULL;
	deque->back = NULL;
	return (deque);
}
