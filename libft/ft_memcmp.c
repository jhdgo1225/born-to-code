/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devpark <devpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:11:06 by jonghopa          #+#    #+#             */
/*   Updated: 2023/10/03 23:16:21 by devpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include	"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	cmp1;
	unsigned char	cmp2;

	i = 0;
	while (i < n)
	{
		cmp1 = *((unsigned char *)s1 + i);
		cmp2 = *((unsigned char *)s2 + i);
		if (cmp1 != cmp2)
			return (cmp1 - cmp2);
		i++;
	}
	return (0);
}
