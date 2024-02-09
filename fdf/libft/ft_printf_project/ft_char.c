/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:40:02 by jonghopa          #+#    #+#             */
/*   Updated: 2023/06/29 18:16:57 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(va_list arg_ptr)
{
	char	ch;
	int		check;

	ch = (char)va_arg(arg_ptr, int);
	check = write(1, &ch, 1);
	return (check);
}
