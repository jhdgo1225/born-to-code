/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:26:28 by jonghopa          #+#    #+#             */
/*   Updated: 2023/06/29 18:17:26 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_decimal(va_list arg_ptr)
{
	long	k;
	int		check;
	int		cnt;

	cnt = 0;
	k = (long)va_arg(arg_ptr, int);
	if (k == 0)
	{
		check = write(1, &"0", 1);
		return (check);
	}
	if (k < 0)
	{
		check = write(1, &"-", 1);
		if (check == -1)
			return (-1);
		k *= -1;
		cnt += 1;
	}
	check = ft_putnbr_special(k);
	if (check == -1)
		return (-1);
	cnt += check;
	return (cnt);
}
