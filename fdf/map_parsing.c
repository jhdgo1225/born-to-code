/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:09:03 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/22 16:50:24 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_atoi_hex_in_fdf(char *str)
{
	unsigned int	decimal;
	int				i;

	decimal = 0;
	i = 2;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		decimal <<= 4;
		if (str[i] >= '0' && str[i] <= '9')
			decimal += (str[i] - '0');
		else if (str[i] >= 'A' && str[i] <= 'F')
			decimal += (str[i] - 55);
		else if (str[i] >= 'a' && str[i] <= 'f')
			decimal += (str[i] - 87);
		i++;
	}
	return (decimal);
}

void	process_data(t_map *map, int coords_idx, char **info, int wd_cnt)
{
	unsigned int	color_info;

	map->coords[coords_idx].x = coords_idx % map->column;
	map->coords[coords_idx].y = coords_idx / map->column;
	map->coords[coords_idx].z = ft_atoi(info[0]);
	if (wd_cnt == 1)
		color_info = 0xFFFFFF;
	else
		color_info = ft_atoi_hex_in_fdf(info[1]);
	map->coords[coords_idx].opacity = (color_info >> 24) & 0xFF;
	map->coords[coords_idx].red = (color_info >> 16) & 0xFF;
	map->coords[coords_idx].green = (color_info >> 8) & 0xFF;
	map->coords[coords_idx].blue = (color_info >> 0) & 0xFF;
}

int	parse_last_info(t_map *map, int coords_idx, char *element)
{
	char	**info;
	int		wd_cnt;

	info = ft_split(element, ',');
	if (info == NULL)
		return (-1);
	wd_cnt = count_words(info);
	if (!(wd_cnt >= 1 && wd_cnt <= 2)
		|| (wd_cnt == 1 && check_num_last(info[0]))
		|| (wd_cnt == 2 && (check_num(info[0]) || check_hex_last(info[1]))))
	{
		free_perfectly_on_main(info);
		return (-1);
	}
	process_data(map, coords_idx, info, wd_cnt);
	free_perfectly_on_main(info);
	return (0);
}

int	parse_info(t_map *map, int coords_idx, char *element)
{
	char	**info;
	size_t	wd_cnt;

	info = ft_split(element, ',');
	if (info == NULL)
		return (-1);
	wd_cnt = count_words(info);
	if ((wd_cnt >= 3 || wd_cnt <= 0)
		|| (wd_cnt == 1 && check_num(info[0]))
		|| (wd_cnt == 2 && (check_num(info[0]) || check_hex(info[1]))))
	{
		free_perfectly_on_main(info);
		return (-1);
	}
	process_data(map, coords_idx, info, wd_cnt);
	free_perfectly_on_main(info);
	return (0);
}

int	parse_fdf_file_line(t_map *map, int line_idx, char *str)
{
	int		i;
	int		flag;
	int		wd_cnt;
	char	**parse;

	parse = ft_split(str, ' ');
	if (parse == NULL)
		return (-1);
	wd_cnt = calc_ret_wd_cnt(parse);
	i = 0;
	while (parse[i] != NULL)
	{
		if (parse[i + 1] == NULL)
			flag = parse_last_info(map, line_idx * map->column + i, parse[i]);
		else
			flag = parse_info(map, line_idx * map->column + i, parse[i]);
		if (flag == -1)
		{
			free_perfectly_on_main(parse);
			return (-1);
		}
		i++;
	}
	free_perfectly_on_main(parse);
	return (wd_cnt);
}
