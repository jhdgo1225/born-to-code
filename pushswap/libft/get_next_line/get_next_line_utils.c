/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:00:28 by jonghopa          #+#    #+#             */
/*   Updated: 2023/07/16 14:11:12 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*gnl_strchr(const char *str, int c)
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char)c;
	while (str[i] != '\0' && str[i] != ch)
		i++;
	if (ch != '\0' && str[i] == '\0')
		return (0);
	return ((char *)(str + i));
}

char	*gnl_strndup(const char *str, size_t size)
{
	size_t	i;
	char	*ret;

	i = 0;
	while (str[i] != '\0' && i < size)
		i++;
	ret = (char *)malloc(i + 1);
	if (ret == 0)
		return (0);
	i = 0;
	while (str[i] != '\0' && i < size)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new_str == 0)
		return (0);
	i = 0;
	new_str[s1_len + s2_len] = 0;
	while (i < s1_len)
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
		new_str[i++] = s2[j++];
	return (new_str);
}
