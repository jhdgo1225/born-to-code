/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:47:56 by jonghopa          #+#    #+#             */
/*   Updated: 2023/06/29 18:17:20 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_conversion(char conversion, va_list arg_ptr)
{
	size_t	cnt;

	if (conversion == 'd' || conversion == 'i')
		cnt = ft_decimal(arg_ptr);
	else if (conversion == 'c')
		cnt = ft_char(arg_ptr);
	else if (conversion == 's')
		cnt = ft_string(arg_ptr);
	else if (conversion == 'u')
		cnt = ft_unsigned(arg_ptr);
	else if (conversion == 'x')
		cnt = ft_hex(arg_ptr, 0);
	else if (conversion == 'X')
		cnt = ft_hex(arg_ptr, 1);
	else if (conversion == 'p')
		cnt = ft_addr(arg_ptr);
	else if (conversion == '%')
		cnt = ft_percent();
	else
		cnt = -1;
	return (cnt);
}
