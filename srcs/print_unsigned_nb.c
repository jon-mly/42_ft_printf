/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_nb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:33:03 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/02/02 12:42:10 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	load_unsigned_type(t_format *format, va_list args)
{
	if (format->j_flag)
		format->type.uimax = va_arg(args, uintmax_t);
	else if (format->ll_flag)
		format->type.uimax = va_arg(args, unsigned long long int);
	else if (format->z_flag)
		format->type.uimax = va_arg(args, size_t);
	else if (format->l_flag)
		format->type.uimax = va_arg(args, unsigned long int);
	else if (format->h_flag)
		format->type.uimax = (unsigned short int)va_arg(args, int);
	else if (format->hh_flag)
		format->type.uimax = (unsigned char)va_arg(args, int);
	else
		format->type.uimax = va_arg(args, unsigned int);
}

/*
** Return the elements to be added before any sign
** Only concerns width without '-' or '0' flags
*/

int		left_u_fill(t_format *format, int nb_len)
{
	char	*fill;
	int		len;
	int		max_len;

	if (format->width > 0 && !(format->minus_flag) && !(format->zero_flag))
	{
		max_len = (nb_len > format->precision) ? nb_len : format->precision;
		if (format->width > max_len)
		{
			len = format->width - max_len -
				(format->plus_flag || format->space_flag);
			if (format->sharp_flag && format->o_type)
				len -= 1;
			else if (format->sharp_flag && (format->x_type || format->X_type))
				len -= 2;
		}
		else
			len = 0;
		len = (len < 0) ? 0 : len;
		fill = ft_strnew(len);
		ft_memset(fill, ' ', len);
		return (ft_pop(fill));
	}
	return (0);
}

/*
** Return the zeros to be added between the sign (if any) and the number
** If width + precision, concerns precision. If no precision, width.
** '0' flag is handled here.
*/

int		middle_u_fill(t_format *format, int nb_len)
{
	char	*fill;
	int		len;

	if (format->precision >= 0 && format->precision > nb_len)
		len = format->precision - nb_len;
	else if (format->zero_flag && format->precision < 0 && format->width >= 0 &&
			format->width > nb_len && !(format->minus_flag))
	{
		len = format->width - nb_len;
		if (format->sharp_flag && format->o_type)
			len -= 1;
		else if (format->sharp_flag && (format->x_type || format->X_type))
			len -= 2;
	}
	else
		len = 0;
	len = (len < 0) ? 0 : len;
	fill = ft_strnew(len);
	ft_memset(fill, '0', len);
	return (ft_pop(fill));
}

/*
** Return the spaces to be added right after the number
** Only concerns minus flag if no precision
*/

int		right_u_fill(t_format *format, int nb_len)
{
	char	*fill;
	int		len;
	int		max_len;

	max_len = (nb_len >= format->precision) ? nb_len : format->precision;
	if (!(format->minus_flag && format->width > max_len))
		return (0);
	len = format->width - max_len;
	if (format->sharp_flag && format->o_type)
		len -= 1;
	else if (format->sharp_flag && (format->x_type || format->X_type))
		len -= 2;
	len = (len < 0) ? 0 : len;
	fill = ft_strnew(len);
	ft_memset(fill, ' ', len);
	return (ft_pop(fill));
}

int		print_unsigned_nb(va_list args, t_format *format)
{
	int		total_len;
	char	*converted_value;

	load_unsigned_type(format, args);
	converted_value = ft_unsigned_itoa_base(format->type.uimax, format);
	if (format->type.uimax == 0 && format->precision == 0)
		converted_value = ft_strnew(0);
	total_len = left_u_fill(format, ft_strlen(converted_value));
	if (format->sharp_flag)
	{
		if (format->o_type && !(format->type.uimax == 0 &&
					format->precision < 0))
			total_len += ft_pop_unalloc("0");
		else if (format->x_type && format->type.uimax > 0)
			total_len += ft_pop_unalloc("0x");
		else if (format->X_type && format->type.uimax > 0)
			total_len += ft_pop_unalloc("0X");
	}
	total_len += middle_u_fill(format, ft_strlen(converted_value));
	total_len += ft_pop(converted_value);
	total_len += right_u_fill(format, ft_strlen(converted_value));
	return (total_len);
}
