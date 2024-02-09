/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:35:34 by jonghopa          #+#    #+#             */
/*   Updated: 2023/06/29 18:16:46 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_addr(va_list arg_ptr)
{
	unsigned long	addr;
	int				cnt;
	int				check;

	addr = (unsigned long)va_arg(arg_ptr, void *);
	cnt = 2;
	check = write(1, &"0x", 2);
	if (check == -1)
		return (-1);
	if (addr == 0)
	{
		check = write(1, &"0", 1);
		if (check == -1)
			return (-1);
		return (cnt + check);
	}
	cnt += ft_putnbr_hex(addr, 0);
	return (cnt);
}
