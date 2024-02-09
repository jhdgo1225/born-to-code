/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:31:00 by jonghopa          #+#    #+#             */
/*   Updated: 2023/09/26 18:53:58 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

# include <stdlib.h>

typedef struct s_deque_node
{
	struct s_deque_node	*left;
	struct s_deque_node	*right;
	int					content;
}			t_deque_node;

typedef struct s_deque
{
	t_deque_node		*front;
	t_deque_node		*back;
}			t_deque;

t_deque			*deque_create(void);
t_deque_node	*deque_create_node(int content);
int				deque_push_front(t_deque *deque, int content);
int				deque_push_back(t_deque *deque, int content);
int				deque_front(t_deque *deque);
int				deque_back(t_deque *deque);
void			deque_pop_front(t_deque *deque);
void			deque_pop_back(t_deque *deque);
int				deque_empty(t_deque *deque);
int				deque_size(t_deque *deque);
void			deque_clear(t_deque *deque);
void			deque_rotate(t_deque *deque);
void			deque_reverse_rotate(t_deque *deque);
void			deque_push(t_deque *src, t_deque *dst);
void			deque_swap(t_deque *deque);

#endif
