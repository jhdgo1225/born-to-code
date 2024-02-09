/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghopa <jonghopa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:20:08 by jonghopa          #+#    #+#             */
/*   Updated: 2023/06/29 18:17:49 by jonghopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_putnbr_special(long n);
int		ft_putnbr_hex(unsigned long n, int up_low);
size_t	ft_conversion(char conversion, va_list arg_ptr);
int		ft_char(va_list arg_ptr);
int		ft_decimal(va_list arg_ptr);
int		ft_unsigned(va_list arg_ptr);
int		ft_percent(void);
int		ft_string(va_list arg_ptr);
int		ft_hex(va_list arg_ptr, int up_low);
int		ft_addr(va_list arg_ptr);
int		ft_printf(const char *format, ...);

#endif
