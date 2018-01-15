#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int     main(int ac, char **av)
{
    int custom_return = ft_printf("%.X, %.0X\n", 0, 0);
    printf("CUSTOM RETURN = %d\n", custom_return);
    int system_return = printf("%.X, %.0X\n", 0, 0);
    printf("SYSTEM RETURN = %d\n", system_return);
    return (0);
}
