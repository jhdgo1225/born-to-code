/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:20:16 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/21 22:29:53 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	process_coords_data_of_map(t_map *map, char *file)
{
	int		fd;
	int		line_idx;
	int		check;
	char	*str;

	line_idx = 0;
	fd = open_maps(file);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		check = parse_fdf_file_line(map, line_idx, str);
		free(str);
		if (check == -1 || check != map->column)
			exit(EXIT_FAILURE);
		line_idx++;
	}
	close(fd);
}

void	calc_width_and_height_of_map(t_map *map, char *file)
{
	int		fd;
	char	*str;

	fd = open_maps(file);
	str = get_next_line(fd);
	if (str == NULL)
		exit(EXIT_FAILURE);
	map->column = calc_width(str);
	free(str);
	if (map->column <= 0)
		exit(EXIT_FAILURE);
	map->row = 1;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		map->row += 1;
		free(str);
	}
	close(fd);
}

void	init_maps(t_map *map, char *file)
{
	int	size;

	calc_width_and_height_of_map(map, file);
	size = map->row * map->column;
	map->coords = (t_map_coord *)malloc(sizeof(t_map_coord) * size);
	if (map->coords == NULL)
		exit(EXIT_FAILURE);
	process_coords_data_of_map(map, file);
}
