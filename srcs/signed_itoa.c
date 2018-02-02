#include "ft_printf.h"

/*
** Convert correctly every value up to 19 digits.
*/

static int		len(intmax_t nb)
{
	int len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static void	    fill_str(intmax_t nb, char *str, int size)
{
	int		i;

	i = size - 1;
	while (nb != 0)
	{
		str[i--] = (nb % 10) + '0';
		nb /= 10;
	}
}

char    *ft_absolute_signed_itoa(intmax_t nb)
{
    int     size;
    char    *str;

	if (nb < -9223372036854775807)
		return (ft_strdup("9223372036854775808"));
	nb = (nb < 0) ? nb * -1 : nb;
    if (nb == 0)
		return (ft_strdup("0"));
	size = len(nb);
	if (!(str = ft_strnew(size)))
		return (0);
	fill_str(nb, str, size);
	str[size] = '\0';
	return (str);
}
