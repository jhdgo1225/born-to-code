/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:48:08 by jonghopa          #+#    #+#             */
/*   Updated: 2023/06/29 18:18:13 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(va_list arg_ptr)
{
	int				check;
	unsigned int	u;

	u = va_arg(arg_ptr, unsigned int);
	if (u == 0)
	{
		check = write(1, &"0", 1);
		return (check);
	}
	check = ft_putnbr_special(u);
	return (check);
}
