/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 02:22:25 by jonghopa          #+#    #+#             */
/*   Updated: 2023/03/23 21:14:35 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include	"libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ret;

	i = -1;
	while (s1[++i] != '\0')
		;
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (ret == 0)
		return (0);
	i = -1;
	while (s1[++i] != '\0')
		ret[i] = s1[i];
	ret[i] = '\0';
	return (ret);
}
