#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr_base(unsigned int nbr, char *base);

int     main(int ac, char **av)
{
    printf("%u\n", 123.45);
    ft_printf("%u\n", 123.45);
}
