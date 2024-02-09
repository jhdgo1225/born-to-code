/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:32:38 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/22 12:58:05 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_last_pixel(t_map_coord *coord, t_image *img)
{
	unsigned int	color;

	color = coord->opacity;
	color = (color << 8) | coord->red;
	color = (color << 8) | coord->green;
	color = (color << 8) | coord->blue;
	put_pixel(img, coord->map_x, coord->map_y, color);
}

void	apply_bresenham_one(t_map_coord *p1, t_map_coord *p2, t_image *img)
{
	int	s_x;
	int	s_y;
	int	diff_x;
	int	diff_y;
	int	d[3];

	s_x = p1->map_x;
	s_y = p1->map_y;
	diff_x = sign(p2->map_x - p1->map_x);
	diff_y = sign(p2->map_y - p1->map_y);
	d[0] = 2 * abs(p2->map_x - p1->map_x) - abs(p2->map_y - p1->map_y);
	d[1] = 2 * abs(p2->map_x - p1->map_x);
	d[2] = 2 * (abs(p2->map_x - p1->map_x) - abs(p2->map_y - p1->map_y));
	while (s_y != p2->map_y)
	{
		put_pixel(img, s_x, s_y, lerp_color(p1, p2, s_x, s_y));
		if (d[0] < 0)
			d[0] += d[1];
		else
		{
			d[0] += d[2];
			s_x += diff_x;
		}
		s_y += diff_y;
	}
}

void	apply_bresenham_two(t_map_coord *p1, t_map_coord *p2, t_image *img)
{
	int	s_x;
	int	s_y;
	int	diff_x;
	int	diff_y;
	int	d[3];

	s_x = p1->map_x;
	s_y = p1->map_y;
	diff_x = sign(p2->map_x - p1->map_x);
	diff_y = sign(p2->map_y - p1->map_y);
	d[0] = 2 * abs(p2->map_y - p1->map_y) - abs(p2->map_x - p1->map_x);
	d[1] = 2 * abs(p2->map_y - p1->map_y);
	d[2] = 2 * (abs(p2->map_y - p1->map_y) - abs(p2->map_x - p1->map_x));
	while (s_x != p2->map_x)
	{
		put_pixel(img, s_x, s_y, lerp_color(p1, p2, s_x, s_y));
		if (d[0] < 0)
			d[0] += d[1];
		else
		{
			d[0] += d[2];
			s_y += diff_y;
		}
		s_x += diff_x;
	}
}

void	draw_ln(t_map_coord *p1, t_map_coord *p2, t_image *img)
{
	int	width;
	int	height;

	width = p2->map_x - p1->map_x;
	height = p2->map_y - p1->map_y;
	if (width == 0 || ((height / width) >= 1 || (height / width) <= -1))
		apply_bresenham_one(p1, p2, img);
	else if ((height / width) > -1 && (height / width) < 1)
		apply_bresenham_two(p1, p2, img);
	return ;
}

void	draw_lines(t_map_coord *coords, int row, int col, t_image *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (i != (row - 1))
			{
				draw_ln(&coords[i * col + j], &coords[(i + 1) * col + j], img);
				put_last_pixel(&coords[(i + 1) * col + j], img);
			}
			if (j != col - 1)
			{
				draw_ln(&coords[i * col + j], &coords[i * col + (j + 1)], img);
				put_last_pixel(&coords[i * col + (j + 1)], img);
			}
			j++;
		}
		i++;
	}
}
