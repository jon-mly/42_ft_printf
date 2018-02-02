#include "ft_printf.h"

/*
** Convert correctly every value up to 20 digits in decimal base.
*/

static char 	*base_str(t_format *format)
{
	if (format->o_type)
		return ("01234567");
	if (format->x_type)
		return ("0123456789abcdef");
	if (format->X_type)
		return ("0123456789ABCDEF");
	return ("0123456789");
}

static int		len(uintmax_t nb, char *base)
{
	int		len;
    int     base_size;

	len = 0;
    base_size = ft_strlen(base);
	while (nb != 0)
	{
		nb /= base_size;
		len++;
	}
	return (len);
}

static void	    fill_str(uintmax_t nb, char *str, char *base)
{
	int		size;
	int		i;
    int     base_size;

    base_size = ft_strlen(base);
	size = len(nb, base);
	i = size - 1;
	while (nb != 0)
	{
		str[i--] = base[nb % base_size];
		nb /= base_size;
	}
}

char            *ft_unsigned_itoa_base(uintmax_t nb, t_format *format)
{
	char 	*base;
	char   	*str;
	int	   	i;
	int	   	size;

	i = 0;
	base = base_str(format);
	size = len(nb, base);
    if (nb == 0)
        return (ft_strdup("0"));
	if (!(str = ft_strnew(size)))
		return (0);
	fill_str(nb, str, base);
	str[size] = '\0';
	return (str);
}
