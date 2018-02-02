/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:37:44 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/02/02 12:37:59 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_precision(const char *str, t_format *format, int i)
{
	int		len;

	if (str[i] != '.')
		return (0);
	i++;
	len = 0;
	while (ft_isdigit(str[i + len]))
		len++;
	format->precision = ft_atoi(str + i);
	return (len + 1);
}

int		get_width(const char *str, t_format *format, int i)
{
	int		len;

	len = 0;
	while (ft_isdigit(str[i + len]))
		len++;
	if (len == 0)
		return (0);
	format->width = ft_atoi(str + i);
	return (len);
}
