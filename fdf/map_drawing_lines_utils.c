/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing_lines_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:44:08 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/22 14:36:51 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	sign(int a)
{
	if (a < 0)
		return (-1);
	return (1);
}

int	abs(int a)
{
	if (a < 0)
		a *= (-1);
	return (a);
}

unsigned int	lerp_color(t_map_coord *p1, t_map_coord *p2, int s_x, int s_y)
{
	unsigned int	color;
	int				m1;
	int				m2;
	double			rt;

	if (abs(p2->map_x - p1->map_x) > abs(p2->map_y - p1->map_y))
	{
		m1 = abs(s_x - p1->map_x);
		m2 = abs(p2->map_x - s_x);
	}
	else
	{
		m1 = abs(s_y - p1->map_y);
		m2 = abs(p2->map_y - s_y);
	}
	rt = (double)m1 / (double)(m1 + m2);
	color = (unsigned)((1 - rt) * p1->opacity + rt * p2->opacity);
	color = (color << 8) | (unsigned)((1 - rt) * p1->red + rt * p2->red);
	color = (color << 8) | (unsigned)((1 - rt) * p1->green + rt * p2->green);
	color = (color << 8) | (unsigned)((1 - rt) * p1->blue + rt * p2->blue);
	return (color);
}

void	put_pixel(t_image *img, int x, int y, unsigned int color)
{
	char	*dst;
	int		offset;

	if ((x >= 0 && x < WIN_WIDTH) && (y >= 0 && y < WIN_HEIGHT))
	{
		offset = y * img->line_length + x * (img->bits_per_pixel / 8);
		dst = img->addr + offset;
		*(unsigned int *)dst = color;
	}
}
