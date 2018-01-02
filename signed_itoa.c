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
    int     j;
    char    *str;

    if (nb == 0)
		return ("0\n");
	size = len(nb);
	if (!(str = ft_strnew(size)))
		return (0);
	fill_str(nb, str, size);
	str[size + (nb < 0)] = '\0';
	return (str);
}
