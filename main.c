#include "ft_printf.h"
#include <stdio.h>

int     main(int ac, char **av)
{
    char *str = "Salut";
    int custom_return = ft_printf("%5.2s\n", "this");
    printf("CUSTOM RETURN = %d\n", custom_return);
    int system_return = printf("%5.2s\n", "this");
    printf("SYSTEM RETURN = %d\n", system_return);
    return (0);
}
