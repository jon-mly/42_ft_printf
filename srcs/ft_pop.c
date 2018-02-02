/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:27:30 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/02/02 12:28:07 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Tool to display a string which will then be cleared and freed. Return its
** length.
*/

int		ft_pop(char *str)
{
	int		len;

	len = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (len);
}

/*
** Dedicated to non allocated strings.
*/

int		ft_pop_unalloc(char *str)
{
	int		len;

	len = ft_strlen(str);
	ft_putstr(str);
	return (len);
}
