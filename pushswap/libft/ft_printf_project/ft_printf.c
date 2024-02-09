/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:44:34 by jonghopa          #+#    #+#             */
/*   Updated: 2023/06/29 18:17:37 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg_ptr;
	int		i;
	int		check;
	size_t	tot;

	i = -1;
	tot = 0;
	va_start(arg_ptr, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
			check = ft_conversion(format[i++ + 1], arg_ptr);
		else
			check = write(1, &format[i], 1);
		if (check == -1)
			return (-1);
		tot += check;
	}
	va_end(arg_ptr);
	return (tot);
}
