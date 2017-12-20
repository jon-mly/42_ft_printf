#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr_base(unsigned int nbr, char *base);

int     main(int ac, char **av)
{
    printf("%u %% %i\n", 123, 999);
    ft_printf("%i %% %i\n", 124, 998);
}
