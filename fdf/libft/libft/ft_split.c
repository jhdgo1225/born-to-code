/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:35:54 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/13 20:19:49 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	cnt;
	int		flag;

	i = 0;
	cnt = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (!(s[i] == c) && !flag)
		{
			cnt++;
			flag = 1;
		}
		else if (s[i] == c && flag)
			flag = 0;
		i++;
	}
	return (cnt);
}

static int	cnt_let(char const *s, char c, int s_idx)
{
	int	cnt;

	cnt = 0;
	while (s[s_idx] == c)
		s_idx++;
	while (s[s_idx] != '\0' && !(s[s_idx] == c))
	{
		cnt++;
		s_idx++;
	}
	return (cnt);
}

static void	free_perfectly(char **words, size_t word_cnt)
{
	size_t	i;

	i = 0;
	while (i < word_cnt)
	{
		free(words[i]);
		i++;
	}
	free(words[i]);
	free(words);
}

static size_t	make_word(char *word, char const *s, char c, size_t s_idx)
{
	size_t	i;

	i = 0;
	while (s[s_idx] != '\0' && !(s[s_idx] == c))
		word[i++] = s[s_idx++];
	word[i] = '\0';
	return (s_idx);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	s_idx;
	char	**words;

	words = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (words == 0)
		return (0);
	i = 0;
	s_idx = 0;
	while (i < count_words(s, c))
	{
		while (s[s_idx] == c)
			s_idx++;
		words[i] = (char *)malloc(sizeof(char) * (cnt_let(s, c, s_idx) + 1));
		if (words[i] == 0)
		{
			free_perfectly(words, i);
			return (0);
		}
		s_idx = make_word(words[i], s, c, s_idx) + 1;
		i++;
	}
	words[i] = 0;
	return (words);
}
