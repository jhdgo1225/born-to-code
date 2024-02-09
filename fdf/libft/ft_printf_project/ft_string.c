/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:15:37 by jonghopa          #+#    #+#             */
/*   Updated: 2023/06/29 18:18:02 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(va_list arg_ptr)
{
	char	*str;
	size_t	len;
	int		check;

	str = (char *)va_arg(arg_ptr, void *);
	if (str == 0)
	{
		check = write(1, &"(null)", 6);
		return (check);
	}
	len = ft_strlen(str);
	check = write(1, str, len);
	return (check);
}
