/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:57:05 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/05 21:07:07 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_deque	*qa;
	t_deque	*qb;

	if (argc < 2)
		return (1);
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
	push_swap_up_a(qa, qb, 0, deque_size(qa));
	deque_clear(qa);
	free(qa);
	free(qb);
	return (0);
}
