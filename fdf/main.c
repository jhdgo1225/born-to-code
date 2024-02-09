/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:12:16 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/22 17:08:08 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_args(int argc, char **argv)
{
	char	*is_extension;

	if (argc != 2)
	{
		ft_printf("Usage : ./fdf [FDF File]\n");
		exit(EXIT_FAILURE);
	}
	is_extension = ft_strrchr(argv[1], '.');
	if (is_extension == NULL || ft_strncmp(is_extension, ".fdf", 5) != 0)
	{
		ft_printf("Error: Use a \".fdf\" extention file\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_mlx	vars;
	t_map	fdf_map;

	check_args(argc, argv);
	init_maps(&fdf_map, argv[1]);
	draw_maps(&fdf_map, &vars);
	loop_maps(&vars);
	return (0);
}
