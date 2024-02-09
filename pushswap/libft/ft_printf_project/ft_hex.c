/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:20:21 by jonghopa          #+#    #+#             */
/*   Updated: 2023/06/29 18:17:30 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(va_list arg_ptr, int up_low)
{
	unsigned int	l_num;
	int				check;

	l_num = va_arg(arg_ptr, unsigned int);
	if (l_num == 0)
	{
		check = write(1, &"0", 1);
		return (check);
	}
	check = ft_putnbr_hex(l_num, up_low);
	return (check);
}
