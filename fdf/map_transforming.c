/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_transforming.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:43:55 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/22 17:42:06 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_to_origin(t_map_coord *coords, int row, int col)
{
	int	i;
	int	size;

	size = row * col;
	i = 0;
	while (i < size)
	{
		coords[i].x -= (double)(col - 1) / 2;
		coords[i].y -= (double)(row - 1) / 2;
		i++;
	}
}

void	scale_coords(t_map_coord *coords, int row, int col)
{
	int	i;
	int	size;
	int	z_adjustor;

	size = row * col;
	z_adjustor = row / 20;
	if (z_adjustor == 0)
		z_adjustor = 1;
	i = 0;
	while (i < size)
	{
		coords[i].x *= (WIN_WIDTH / (col * 2));
		coords[i].y *= (WIN_HEIGHT / (row * 2));
		coords[i].z = (coords[i].z * 8) / z_adjustor;
		i++;
	}
}

void	move_to_center_of_window(t_map_coord *coords, int row, int col)
{
	int	i;
	int	size;

	size = row * col;
	i = 0;
	while (i < size)
	{
		coords[i].map_x = (int)coords[i].x;
		coords[i].map_x += (WIN_WIDTH / 2);
		coords[i].map_y = (int)coords[i].y;
		coords[i].map_y += (WIN_HEIGHT / 2);
		i++;
	}
}

void	present_isometric(t_map_coord *coords, int row, int col)
{
	int	size;

	size = row * col;
	move_to_origin(coords, row, col);
	scale_coords(coords, row, col);
	transform_rotation(coords, size);
	move_to_center_of_window(coords, row, col);
}
