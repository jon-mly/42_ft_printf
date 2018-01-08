#include "ft_printf.h"
#include <stdio.h>

int     main(int ac, char **av)
{
    char *str = "Salut";
    int custom_return = ft_printf("%+10.5d CONTENU %#lx %% FIN\n", 125, 10);
    printf("CUSTOM RETURN = %d\n", custom_return);
    int system_return = printf("%+10.5d CONTENU %#lx %% FIN\n", 125, 10);
    printf("SYSTEM RETURN = %d\n", system_return);
    return (0);
}
