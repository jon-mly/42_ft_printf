/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:30:42 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/02/02 12:41:49 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	load_signed_type(t_format *format, va_list args)
{
	if (format->j_flag)
		format->type.imax = va_arg(args, intmax_t);
	else if (format->ll_flag)
		format->type.imax = va_arg(args, long long int);
	else if (format->l_flag)
		format->type.imax = va_arg(args, long int);
	else if (format->z_flag)
		format->type.imax = va_arg(args, size_t);
	else if (format->h_flag)
		format->type.imax = (short int)va_arg(args, int);
	else if (format->hh_flag)
		format->type.imax = (char)va_arg(args, int);
	else
		format->type.imax = va_arg(args, int);
}

/*
** Return the elements to be added before any sign
** Only concerns width without '-' or '0' flags
*/

int		left_fill(t_format *format, int nb_len)
{
	char	*fill;
	int		len;
	int		max_len;

	if (format->width > 0 && !(format->minus_flag) && (!(format->zero_flag) ||
				format->precision > -1))
	{
		max_len = (nb_len > format->precision) ? nb_len : format->precision;
		max_len += format->type.imax < 0 || format->plus_flag ||
			format->space_flag;
		if (format->width > max_len)
			len = format->width - max_len;
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

int		middle_fill(t_format *format, int nb_len)
{
	char	*fill;
	int		len;
	int		sign;

	sign = format->type.imax < 0 || format->plus_flag || format->space_flag;
	if (format->precision >= 0 && format->precision > nb_len)
		len = format->precision - nb_len;
	else if (format->zero_flag && format->width >= 0 &&
			format->width > nb_len + sign && !(format->minus_flag))
		len = format->width - nb_len - sign;
	else
		len = 0;
	if (len <= 0)
		return (0);
	fill = ft_strnew(len);
	ft_memset(fill, '0', len);
	return (ft_pop(fill));
}

/*
** Return the spaces to be added right after the number
** Only concerns minus flag
*/

int		right_fill(t_format *format, int nb_len)
{
	char	*fill;
	int		len;
	int		max_nb_len;

	nb_len += format->type.imax < 0;
	if (format->minus_flag)
	{
		max_nb_len = (nb_len > format->precision) ? nb_len : format->precision;
		if (format->width > max_nb_len)
			len = format->width - max_nb_len -
				((format->plus_flag || format->space_flag) &&
					format->type.imax >= 0);
		else
			len = 0;
		len = (len < 0) ? 0 : len;
		fill = ft_strnew(len);
		ft_memset(fill, ' ', len);
		return (ft_pop(fill));
	}
	return (0);
}

int		print_signed_nb(va_list args, t_format *format)
{
	int		total_len;
	char	*converted_value;

	load_signed_type(format, args);
	converted_value = ft_absolute_signed_itoa(format->type.imax);
	if (format->type.imax == 0 && format->precision == 0)
		converted_value = ft_strnew(0);
	total_len = left_fill(format, ft_strlen(converted_value));
	if (format->type.imax < 0 || format->plus_flag || format->space_flag)
	{
		if (format->type.imax < 0)
			total_len += ft_pop_unalloc("-");
		else if (format->type.imax >= 0 && (format->plus_flag ||
					format->space_flag))
			total_len += ft_pop_unalloc((format->plus_flag) ? "+" : " ");
	}
	total_len += middle_fill(format, ft_strlen(converted_value));
	total_len += ft_pop(converted_value);
	total_len += right_fill(format, ft_strlen(converted_value));
	return (total_len);
}
