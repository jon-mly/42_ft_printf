/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 19:38:27 by jmlynarc          #+#    #+#             */
/*   Updated: 2017/07/15 18:54:03 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_base_size(char *base)
{
	int	i;
	int	j;

	i = -1;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = -1;
		while (++j < i)
		{
			if (base[j] == base[i])
				return (0);
		}
	}
	return (i);
}

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	int 			base_size;
	unsigned int 	abs;

	base_size = get_base_size(base);
	abs = (nbr > 0) ? nbr : -nbr;
	if (base_size < 2)
		return ;
	if (nbr == 0)
	{
		ft_putchar(*(base));
		return ;
	}
	if (nbr < 0)
		ft_putchar('-');
	if (abs >= base_size)
		ft_putnbr_base(abs / base_size, base);
	ft_putchar(*(base + (abs % base_size)));
}
