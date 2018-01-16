#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int     main(int ac, char **av)
{
    int custom_return = ft_printf("% hZ%\n");
    printf("CUSTOM RETURN = %d\n", custom_return);
    int system_return = printf("% hZ%\n");
    printf("SYSTEM RETURN = %d\n", system_return);
    return (0);
}
