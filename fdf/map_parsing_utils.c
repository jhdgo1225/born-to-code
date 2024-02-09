/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:31:39 by devpark           #+#    #+#             */
/*   Updated: 2023/10/16 16:26:25 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	calc_ret_wd_cnt(char **parse)
{
	int	wd_cnt;

	wd_cnt = count_words(parse);
	if (wd_cnt == 0)
		return (0);
	wd_cnt -= (!ft_strncmp(parse[wd_cnt - 1], "\n", 2));
	return (wd_cnt);
}

int	check_num(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != 0)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+')
			&& ft_isdigit(str[i + 1]))
		{
			i++;
			continue ;
		}
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int	check_num_last(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\n')
	{
		if (str[i] == 0)
			break ;
		if (i == 0 && (str[i] == '-' || str[i] == '+')
			&& ft_isdigit(str[i + 1]))
		{
			i++;
			continue ;
		}
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

int	check_hex(char *str)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	if (len < 3 || len > 10)
		return (-1);
	if (str[0] != '0' || str[1] != 'x')
		return (-1);
	i = 2;
	while (str[i] != 0)
	{
		if (ft_isdigit(str[i]) == 0
			&& !(str[i] >= 'A' && str[i] <= 'F')
			&& !(str[i] >= 'a' && str[i] <= 'f'))
			return (-1);
		i++;
	}
	return (0);
}

int	check_hex_last(char *str)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	if (len < 4 || len > 11)
		return (-1);
	if (str[0] != '0' || str[1] != 'x')
		return (-1);
	i = 2;
	while (str[i] != '\n')
	{
		if (str[i] == 0)
			break ;
		if (ft_isdigit(str[i]) == 0
			&& !(str[i] >= 'A' && str[i] <= 'F')
			&& !(str[i] >= 'a' && str[i] <= 'f'))
			return (-1);
		i++;
	}
	return (0);
}
