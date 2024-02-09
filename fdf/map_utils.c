/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:08:16 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/16 20:13:46 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	open_maps(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: Open Failed.\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	calc_width(char *str)
{
	char	**strs;
	int		wd_cnt;

	strs = ft_split(str, ' ');
	if (strs == NULL)
		return (-1);
	wd_cnt = calc_ret_wd_cnt(strs);
	free_perfectly_on_main(strs);
	return (wd_cnt);
}

int	count_words(char **strs)
{
	int	cnt;

	cnt = 0;
	while (strs[cnt] != 0)
		cnt++;
	return (cnt);
}

void	free_perfectly_on_main(char **words)
{
	int	i;

	i = 0;
	while (words[i] != NULL)
	{
		free(words[i]);
		i++;
	}
	free(words[i]);
	free(words);
}
