/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:28:52 by jonghopa          #+#    #+#             */
/*   Updated: 2023/06/29 18:17:53 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long n, int up_low)
{
	char	print_ch;
	int		cnt;
	int		check;

	cnt = 0;
	if (n == 0)
		return (cnt);
	check = ft_putnbr_hex(n / 16, up_low);
	if (check == -1)
		return (-1);
	cnt += check;
	if (n % 16 >= 10 && n % 16 <= 15)
	{
		if (up_low == 0)
			print_ch = 87 + (n % 16);
		else
			print_ch = 55 + (n % 16);
	}
	else
		print_ch = 48 + (n % 16);
	check = write(1, &print_ch, 1);
	if (check == -1)
		return (-1);
	cnt += check;
	return (cnt);
}
