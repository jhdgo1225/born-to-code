/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:41:15 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/05 20:25:08 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_array(int *origin, size_t cnt)
{
	int		*copy;
	size_t	i;

	copy = (int *)malloc(sizeof(int) * cnt);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < cnt)
	{
		copy[i] = origin[i];
		i++;
	}
	return (copy);
}

int	coord_compression(int *origin, int *res, size_t cnt)
{
	size_t	i;
	int		*tmp;
	int		*sorted;

	tmp = (int *)malloc(sizeof(int) * cnt);
	if (tmp == NULL)
		return (0);
	sorted = copy_array(origin, cnt);
	if (sorted == NULL)
	{
		free(tmp);
		return (0);
	}
	merge_sort(sorted, tmp, 0, cnt);
	i = 0;
	while (i < cnt)
	{
		res[i] = binary_search(sorted, origin[i], 0, cnt);
		i++;
	}
	free(sorted);
	free(tmp);
	return (1);
}

int	check_integer(const char *str)
{
	int				sign;
	int				i;
	unsigned long	ret;
	unsigned long	temp;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	i += (str[i] == '+' || str[i] == '-');
	ret = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = ret * 10 + (str[i] - '0');
		if (sign < 0 && temp > (unsigned long)INT_MAX + 1)
			return (0);
		else if (sign > 0 && temp > INT_MAX)
			return (0);
		ret = temp;
		i++;
	}
	return (1);
}

int	check_args_is_num(char **strs)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (strs[0] == NULL)
		return (0);
	while (strs[i] != NULL)
	{
		j = 0;
		if (strs[i][0] == 0)
			return (0);
		while (strs[i][j] != 0)
		{
			if (j == 0 && (strs[i][j] == '-' || strs[i][j] == '+')
				&& ft_isdigit(strs[i][j + 1]))
			{
				j++;
				continue ;
			}
			if (ft_isdigit(strs[i][j++]) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	cvt_integer(int *nums, char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i] != 0)
	{
		if (!check_args_is_num(strs) || !check_integer(strs[i]))
		{
			free(nums);
			return (0);
		}
		nums[i] = ft_atoi(strs[i]);
		i++;
	}
	return (1);
}
