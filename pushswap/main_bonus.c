/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:28:08 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/05 21:12:12 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_deques(t_deque *qa, t_deque *qb)
{
	deque_clear(qa);
	deque_clear(qb);
	free(qa);
	free(qb);
}

int	main(int argc, char **argv)
{
	t_deque	*qa;
	t_deque	*qb;

	qa = parse_args(argc, argv);
	if (qa == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	qb = deque_create();
	if (qb == NULL)
	{
		ft_printf("Error\n");
		deque_clear(qa);
		free(qa);
		return (1);
	}
	if (cmd_processors(qa, qb) == 0)
	{
		ft_printf("Error\n");
		free_deques(qa, qb);
		return (1);
	}
	free_deques(qa, qb);
	return (0);
}
