/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:34:39 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/02/02 12:35:26 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		wstrlen(wchar_t *wstring)
{
	int		i;

	i = 0;
	if (wstring == NULL)
		return (0);
	while (wstring[i])
		i++;
	return (i);
}

static char		*null_str(int precision)
{
	char	*tmp;

	if (precision >= (int)ft_strlen("(null)") || precision < 0)
		return (ft_strdup("(null)"));
	tmp = ft_strnew(precision);
	ft_memcpy(tmp, "(null)", precision);
	return (tmp);
}

static char		*wstrconvert(wchar_t *wstring, t_format *format)
{
	int		i;
	int		max_len;
	char	*converted_str;
	char	*str_tmp;
	char	*wchar_tmp;

	i = -1;
	if (wstring == NULL)
		return (null_str(format->precision));
	max_len = (format->precision < 0 || wstrlen(wstring) <= format->precision) ?
		wstrlen(wstring) : format->precision;
	converted_str = ft_strnew(0);
	while (wstring[++i] && i < max_len)
	{
		wchar_tmp = get_converted_wchar(wstring[i]);
		str_tmp = converted_str;
		converted_str = ft_strjoin(str_tmp, wchar_tmp);
		ft_strdel(&wchar_tmp);
		ft_strdel(&str_tmp);
	}
	return (converted_str);
}

int				print_wstring(va_list args, t_format *format)
{
	char	*printable;
	char	*spaces;

	format->type.wstr = va_arg(args, wchar_t*);
	if (wstrlen(format->type.wstr) >= format->width)
		return (ft_pop(wstrconvert(format->type.wstr, format)));
	spaces = get_required_spaces(format, format->width -
			wstrlen(format->type.wstr));
	if (format->minus_flag)
		printable = ft_strjoin(wstrconvert(format->type.wstr, format), spaces);
	else
		printable = ft_strjoin(spaces, wstrconvert(format->type.wstr,
					format));
	ft_strdel(&spaces);
	return (ft_pop(printable));
}
