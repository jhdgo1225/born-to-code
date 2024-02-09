/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_illustrating.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:26:41 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/22 13:04:55 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_maps(t_map *map, t_mlx *vars)
{
	t_image	img;

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "JONGHOPA");
	img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	present_isometric(map->coords, map->row, map->column);
	draw_lines(map->coords, map->row, map->column, &img);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}
