/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:38:01 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/02/02 12:42:20 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_one_byte(unsigned int wc_value)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = (char)(wc_value);
	return (str);
}

static char		*get_two_bytes(unsigned int wc_value)
{
	char	*str;

	str = ft_strnew(2);
	str[0] = (char)(192 | (wc_value >> 6 & 63));
	str[1] = (char)(128 | (wc_value & 63));
	return (str);
}

static char		*get_three_bytes(unsigned int wc_value)
{
	char	*str;

	str = ft_strnew(3);
	str[0] = (char)(224 | (wc_value >> 12 & 63));
	str[1] = (char)(128 | (wc_value >> 6 & 63));
	str[2] = (char)(128 | (wc_value & 63));
	return (str);
}

static char		*get_four_bytes(unsigned int wc_value)
{
	char	*str;

	str = ft_strnew(4);
	str[0] = (char)(240 | (wc_value >> 18 & 63));
	str[1] = (char)(128 | (wc_value >> 12 & 63));
	str[2] = (char)(128 | (wc_value >> 6 & 63));
	str[3] = (char)(128 | (wc_value & 63));
	return (str);
}

/*
** Séquençage par octet (par tranche de 2^(n*8 - 1))
*/

char			*get_converted_wchar(wchar_t wc)
{
	unsigned int	wc_value;

	wc_value = (unsigned int)wc;
	if (wc_value <= 127)
		return (get_one_byte(wc_value));
	if (wc_value <= 2047)
		return (get_two_bytes(wc_value));
	if (wc_value <= 65535)
		return (get_three_bytes(wc_value));
	return (get_four_bytes(wc_value));
}
