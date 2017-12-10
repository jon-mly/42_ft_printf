#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr_base(int nbr, char *base);

int     main(int ac, char **av)
{
    //printf("%i\n", 123);
    //ft_printf("%i\n", 123);
    ft_putnbr_base(100, "0123456789ABCDEF");
}
