/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rotating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:18:11 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/22 16:18:19 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#ifndef PI
# define PI 3.1415926
#endif

void	rotate_z(t_map_coord *coord)
{
	double	h_angle;
	double	old_x;
	double	old_y;

	h_angle = (45) * PI / 180;
	old_x = coord->x;
	old_y = coord->y;
	coord->x = cos(h_angle) * old_x + (-1) * sin(h_angle) * old_y;
	coord->y = sin(h_angle) * old_x + cos(h_angle) * old_y;
}

void	rotate_x(t_map_coord *coord)
{
	double	v_angle;
	double	old_y;
	double	old_z;

	v_angle = (35.264) * PI / 180;
	old_y = coord->y;
	old_z = coord->z;
	coord->y = cos(v_angle) * old_y + (-1) * sin(v_angle) * old_z;
	coord->z = sin(v_angle) * old_y + cos(v_angle) * old_z;
}

void	transform_rotation(t_map_coord *coords, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		rotate_z(&coords[i]);
		rotate_x(&coords[i]);
		i++;
	}
}
