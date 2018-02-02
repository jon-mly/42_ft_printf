/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:36:19 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/02/02 12:41:29 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_format_unsigned(t_format *format, char type)
{
	if (type == 'O' || type == 'U')
		format->l_flag = 1;
	if (type == 'o' || type == 'O')
		format->o_type = 1;
	else if (type == 'u' || type == 'U')
		format->u_type = 1;
	else if (type == 'x')
		format->x_type = 1;
	else if (type == 'X')
		format->X_type = 1;
}

int		type_print(va_list args, t_format *format, const char *str, int i)
{
	if (!(ft_char_search(str + i, "sSdDioOuUxXpcC%")))
		return ((str[i]) ? print_no_flag(format, str[i]) : 0);
	if (str[i] == 's')
		return (print_string(args, format));
	if (str[i] == 'S')
		return (print_wstring(args, format));
	if (str[i] == 'c')
		return (print_char(args, format));
	if (str[i] == 'C')
		return (print_wchar(args, format));
	if (str[i] == 'D' || str[i] == 'd' || str[i] == 'i')
	{
		format->l_flag = (format->l_flag == 1 || str[i] == 'D');
		return (print_signed_nb(args, format));
	}
	if (ft_char_search(str + i, "ouxXUO"))
	{
		set_format_unsigned(format, str[i]);
		return (print_unsigned_nb(args, format));
	}
	if (str[i] == 'p')
		return (print_pointer(args, format));
	if (str[i] == '%')
		return (print_percent(format));
	return (-1);
}
