/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing_utils_2_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:42:01 by jonghopa          #+#    #+#             */
/*   Updated: 2023/09/30 17:08:38 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_perfectly_on_main(char **words)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = count_word(words);
	while (i < cnt)
	{
		free(words[i]);
		i++;
	}
	free(words[i]);
	free(words);
}

size_t	count_word(char **strs)
{
	size_t	cnt;

	cnt = 0;
	while (strs[cnt] != 0)
		cnt++;
	return (cnt);
}

int	count_tokens(int argc, char **argv)
{
	char	**strs;
	int		tmp;
	int		cnt;
	int		i;

	cnt = 0;
	i = 1;
	while (i < argc)
	{
		strs = ft_split(argv[i], ' ');
		if (strs == NULL)
			return (-1);
		tmp = count_word(strs);
		if (tmp == 0)
		{
			free_perfectly_on_main(strs);
			return (-1);
		}
		cnt += tmp;
		free_perfectly_on_main(strs);
		i++;
	}
	return (cnt);
}

int	func_for_tokenize_args(char **strs, char **tmp, int now)
{
	int	i;
	int	res;

	i = 0;
	res = now;
	while (tmp[i] != NULL)
	{
		strs[res] = ft_strdup(tmp[i]);
		if (strs[res] == NULL)
		{
			free_perfectly_on_main(tmp);
			free_perfectly(strs, res);
			return (-1);
		}
		res++;
		i++;
	}
	return (res);
}

int	tokenize_args(int argc, char **argv, char **strs)
{
	char	**tmp;
	int		idx[2];

	idx[0] = 1;
	idx[1] = 0;
	while (idx[0] < argc)
	{
		tmp = ft_split(argv[idx[0]], ' ');
		if (tmp == NULL)
		{
			free_perfectly(strs, idx[1]);
			return (0);
		}
		idx[1] = func_for_tokenize_args(strs, tmp, idx[1]);
		if (idx[1] == -1)
			return (0);
		free_perfectly_on_main(tmp);
		idx[0]++;
	}
	strs[idx[1]] = NULL;
	return (1);
}
