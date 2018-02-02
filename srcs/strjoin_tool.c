/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:35:52 by jmlynarc          #+#    #+#             */
/*   Updated: 2018/02/02 12:36:13 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The returned value should be given to s1 !
*/

char	*strcombine(char *s1, char *s2)
{
	char	*tmp;
	char	*result;

	tmp = s2;
	if (ft_strlen(tmp) > 0)
		result = ft_strjoin(s1, tmp);
	else
		result = s1;
	ft_strdel(&tmp);
	return (result);
}
