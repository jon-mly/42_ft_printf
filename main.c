#include "ft_printf.h"
#include <stdio.h>

int     main(int ac, char **av)
{
    char *str = "Salut";
    ft_printf("%p\n", str);
    //printf("%0d\n", 0);
    return (0);
}
