/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_special.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:56:07 by jonghopa          #+#    #+#             */
/*   Updated: 2023/06/29 18:17:58 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_special(long n)
{
	int		cnt;
	int		check;
	char	ch;

	cnt = 0;
	if (n >= 0 && n <= 9)
	{
		ch = 48 + n;
		check = write(1, &ch, 1);
		return (check);
	}
	else
	{
		check = ft_putnbr_special(n / 10);
		if (check == -1)
			return (-1);
		cnt += check;
		check = ft_putnbr_special(n % 10);
		if (check == -1)
			return (-1);
		cnt += check;
	}
	return (cnt);
}
