/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   description_string_analysis_tools.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:26:57 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/02/02 12:39:10 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Return 1 if one of the char in searched matches the first char pointed By
** position.
*/

int		ft_char_search(const char *position, char *searched)
{
	int		i;

	i = -1;
	while (searched[++i])
	{
		if (ft_strchr(position, searched[i]) == position)
			return (1);
	}
	return (0);
}
