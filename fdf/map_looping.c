/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_looping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:30:18 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/22 17:21:32 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#ifndef KEY_PRESS
# define KEY_PRESS 2
#endif

#ifndef DESTROY_NOTIFY
# define DESTROY_NOTIFY 17
#endif

int	close_win_pressing_esc(int keycode, void *var)
{
	t_mlx	*tmp;

	tmp = var;
	if (keycode == 53)
	{
		mlx_destroy_window(tmp->mlx, tmp->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_win_clicking_cross_btn(void *var)
{
	t_mlx	*tmp;

	tmp = var;
	mlx_destroy_window(tmp->mlx, tmp->win);
	exit(EXIT_SUCCESS);
	return (0);
}

void	loop_maps(t_mlx *vars)
{
	mlx_hook(vars->win, KEY_PRESS, 1L << 0, close_win_pressing_esc, vars);
	mlx_hook(vars->win, DESTROY_NOTIFY, 0, close_win_clicking_cross_btn, vars);
	mlx_loop(vars->mlx);
}
