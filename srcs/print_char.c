/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:28:44 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/02/02 12:29:01 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pop_char(char c)
{
	ft_putchar(c);
	return (1);
}

int		print_char(va_list args, t_format *format)
{
	char	*spaces;

	if (format->l_flag)
		return (print_wchar(args, format));
	format->type.c = (char)va_arg(args, int);
	if (format->width <= 1)
		return (ft_pop_char(format->type.c));
	spaces = ft_strnew(format->width - 1);
	ft_memset(spaces, format->zero_flag ? '0' : ' ', format->width - 1);
	if (format->minus_flag)
		return (ft_pop_char(format->type.c) + ft_pop(spaces));
	else
		return (ft_pop(spaces) + ft_pop_char(format->type.c));
}
